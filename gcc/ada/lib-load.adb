------------------------------------------------------------------------------
--                                                                          --
--                         GNAT COMPILER COMPONENTS                         --
--                                                                          --
--                             L I B . L O A D                              --
--                                                                          --
--                                 B o d y                                  --
--                                                                          --
--          Copyright (C) 1992-2006, Free Software Foundation, Inc.         --
--                                                                          --
-- GNAT is free software;  you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 2,  or (at your option) any later ver- --
-- sion.  GNAT is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License --
-- for  more details.  You should have  received  a copy of the GNU General --
-- Public License  distributed with GNAT;  see file COPYING.  If not, write --
-- to  the  Free Software Foundation,  51  Franklin  Street,  Fifth  Floor, --
-- Boston, MA 02110-1301, USA.                                              --
--                                                                          --
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

with Atree;    use Atree;
with Debug;    use Debug;
with Einfo;    use Einfo;
with Errout;   use Errout;
with Fname;    use Fname;
with Fname.UF; use Fname.UF;
with Namet;    use Namet;
with Nlists;   use Nlists;
with Nmake;    use Nmake;
with Opt;      use Opt;
with Osint;    use Osint;
with Osint.C;  use Osint.C;
with Output;   use Output;
with Par;
with Restrict; use Restrict;
with Scn;      use Scn;
with Sinfo;    use Sinfo;
with Sinput;   use Sinput;
with Sinput.L; use Sinput.L;
with Stand;    use Stand;
with Tbuild;   use Tbuild;
with Uname;    use Uname;

package body Lib.Load is

   -----------------------
   -- Local Subprograms --
   -----------------------

   function From_Limited_With_Chain (Lim : Boolean) return Boolean;
   --  Check whether a possible circular dependence includes units that
   --  have been loaded through limited_with clauses, in which case there
   --  is no real circularity.

   function Spec_Is_Irrelevant
     (Spec_Unit : Unit_Number_Type;
      Body_Unit : Unit_Number_Type) return Boolean;
   --  The Spec_Unit and Body_Unit parameters are the unit numbers of the
   --  spec file that corresponds to the main unit which is a body. This
   --  function determines if the spec file is irrelevant and will be
   --  overridden by the body as described in RM 10.1.4(4). See description
   --  in "Special Handling of Subprogram Bodies" for further details.

   procedure Write_Dependency_Chain;
   --  This procedure is used to generate error message info lines that
   --  trace the current dependency chain when a load error occurs.

   -------------------------------
   -- Create_Dummy_Package_Unit --
   -------------------------------

   function Create_Dummy_Package_Unit
     (With_Node : Node_Id;
      Spec_Name : Unit_Name_Type) return Unit_Number_Type
   is
      Unum         : Unit_Number_Type;
      Cunit_Entity : Entity_Id;
      Cunit        : Node_Id;
      Du_Name      : Node_Or_Entity_Id;
      End_Lab      : Node_Id;
      Save_CS      : constant Boolean := Get_Comes_From_Source_Default;

   begin
      --  The created dummy package unit does not come from source

      Set_Comes_From_Source_Default (False);

      --  Normal package

      if Nkind (Name (With_Node)) = N_Identifier then
         Cunit_Entity :=
           Make_Defining_Identifier (No_Location,
             Chars => Chars (Name (With_Node)));
         Du_Name := Cunit_Entity;
         End_Lab := New_Occurrence_Of (Cunit_Entity, No_Location);

      --  Child package

      else
         Cunit_Entity :=
           Make_Defining_Identifier (No_Location,
             Chars => Chars (Selector_Name (Name (With_Node))));
         Du_Name :=
           Make_Defining_Program_Unit_Name (No_Location,
             Name => New_Copy_Tree (Prefix (Name (With_Node))),
             Defining_Identifier => Cunit_Entity);

         Set_Is_Child_Unit (Cunit_Entity);

         End_Lab :=
           Make_Designator (No_Location,
             Name => New_Copy_Tree (Prefix (Name (With_Node))),
             Identifier => New_Occurrence_Of (Cunit_Entity, No_Location));
      end if;

      Set_Scope (Cunit_Entity, Standard_Standard);

      Cunit :=
        Make_Compilation_Unit (No_Location,
          Context_Items => Empty_List,
          Unit =>
            Make_Package_Declaration (No_Location,
              Specification =>
                Make_Package_Specification (No_Location,
                  Defining_Unit_Name   => Du_Name,
                  Visible_Declarations => Empty_List,
                  End_Label            => End_Lab)),
          Aux_Decls_Node =>
            Make_Compilation_Unit_Aux (No_Location));

      --  Mark the dummy package as analyzed to prevent analysis of this
      --  (non-existent) unit in -gnatQ mode because at the moment the
      --  structure and attributes of this dummy package does not allow
      --  a normal analysis of this unit

      Set_Analyzed (Cunit);

      Units.Increment_Last;
      Unum := Units.Last;

      Units.Table (Unum) := (
        Cunit           => Cunit,
        Cunit_Entity    => Cunit_Entity,
        Dependency_Num  => 0,
        Dynamic_Elab    => False,
        Error_Location  => Sloc (With_Node),
        Expected_Unit   => Spec_Name,
        Fatal_Error     => True,
        Generate_Code   => False,
        Has_RACW        => False,
        Ident_String    => Empty,
        Loading         => False,
        Main_Priority   => Default_Main_Priority,
        Munit_Index     => 0,
        Serial_Number   => 0,
        Source_Index    => No_Source_File,
        Unit_File_Name  => Get_File_Name (Spec_Name, Subunit => False),
        Unit_Name       => Spec_Name,
        Version         => 0);

      Set_Comes_From_Source_Default (Save_CS);
      Set_Error_Posted (Cunit_Entity);
      Set_Error_Posted (Cunit);
      return Unum;
   end Create_Dummy_Package_Unit;

   -----------------------------
   -- From_Limited_With_Chain --
   -----------------------------

   function From_Limited_With_Chain (Lim : Boolean) return Boolean is
   begin
      --  True if the current load operation is through a limited_with clause

      if Lim then
         return True;

      --  Examine the Load_Stack to locate any previous Limited_with clause

      elsif Load_Stack.Last - 1 > Load_Stack.First then
         for U in Load_Stack.First .. Load_Stack.Last - 1 loop
            if Load_Stack.Table (U).From_Limited_With then
               return True;
            end if;
         end loop;
      end if;

      return False;
   end From_Limited_With_Chain;

   ----------------
   -- Initialize --
   ----------------

   procedure Initialize is
   begin
      Units.Init;
      Load_Stack.Init;
   end Initialize;

   ------------------------
   -- Initialize_Version --
   ------------------------

   procedure Initialize_Version (U : Unit_Number_Type) is
   begin
      Units.Table (U).Version := Source_Checksum (Source_Index (U));
   end Initialize_Version;

   ----------------------
   -- Load_Main_Source --
   ----------------------

   procedure Load_Main_Source is
      Fname : File_Name_Type;

   begin
      Load_Stack.Increment_Last;
      Load_Stack.Table (Load_Stack.Last) := (Main_Unit, False);

      --  Initialize unit table entry for Main_Unit. Note that we don't know
      --  the unit name yet, that gets filled in when the parser parses the
      --  main unit, at which time a check is made that it matches the main
      --  file name, and then the Unit_Name field is set. The Cunit and
      --  Cunit_Entity fields also get filled in later by the parser.

      Units.Increment_Last;
      Fname := Next_Main_Source;

      Units.Table (Main_Unit).Unit_File_Name := Fname;

      if Fname /= No_File then
         Main_Source_File := Load_Source_File (Fname);
         Current_Error_Source_File := Main_Source_File;

         Units.Table (Main_Unit) := (
           Cunit           => Empty,
           Cunit_Entity    => Empty,
           Dependency_Num  => 0,
           Dynamic_Elab    => False,
           Error_Location  => No_Location,
           Expected_Unit   => No_Name,
           Fatal_Error     => False,
           Generate_Code   => False,
           Has_RACW        => False,
           Ident_String    => Empty,
           Loading         => True,
           Main_Priority   => Default_Main_Priority,
           Munit_Index     => 0,
           Serial_Number   => 0,
           Source_Index    => Main_Source_File,
           Unit_File_Name  => Fname,
           Unit_Name       => No_Name,
           Version         => Source_Checksum (Main_Source_File));
      end if;
   end Load_Main_Source;

   ---------------
   -- Load_Unit --
   ---------------

   function Load_Unit
     (Load_Name         : Unit_Name_Type;
      Required          : Boolean;
      Error_Node        : Node_Id;
      Subunit           : Boolean;
      Corr_Body         : Unit_Number_Type := No_Unit;
      Renamings         : Boolean          := False;
      From_Limited_With : Boolean          := False) return Unit_Number_Type
   is
      Calling_Unit : Unit_Number_Type;
      Uname_Actual : Unit_Name_Type;
      Unum         : Unit_Number_Type;
      Unump        : Unit_Number_Type;
      Fname        : File_Name_Type;
      Src_Ind      : Source_File_Index;

   --  Start of processing for Load_Unit

   begin
      --  If renamings are allowed and we have a child unit name, then we
      --  must first load the parent to deal with finding the real name.

      if Renamings and then Is_Child_Name (Load_Name) then
         Unump :=
           Load_Unit
             (Load_Name  => Get_Parent_Spec_Name (Load_Name),
              Required   => Required,
              Subunit    => False,
              Renamings  => True,
              Error_Node => Error_Node);

         if Unump = No_Unit then
            return No_Unit;
         end if;

         --  If parent is a renaming, then we use the renamed package as
         --  the actual parent for the subsequent load operation.

         if Nkind (Parent (Cunit_Entity (Unump))) =
           N_Package_Renaming_Declaration
         then
            Uname_Actual :=
              New_Child
                (Load_Name,
                 Get_Unit_Name (Name (Parent (Cunit_Entity (Unump)))));

            --  Save the renaming entity, to establish its visibility when
            --  installing the context. The implicit with is on this entity,
            --  not on the package it renames.

            if Nkind (Error_Node) = N_With_Clause
              and then Nkind (Name (Error_Node)) = N_Selected_Component
            then
               declare
                  Par : Node_Id := Name (Error_Node);

               begin
                  while Nkind (Par) = N_Selected_Component
                    and then Chars (Selector_Name (Par)) /=
                      Chars (Cunit_Entity (Unump))
                  loop
                     Par := Prefix (Par);
                  end loop;

                  --  Case of some intermediate parent is a renaming

                  if Nkind (Par) = N_Selected_Component then
                     Set_Entity (Selector_Name (Par), Cunit_Entity (Unump));

                  --  Case where the ultimate parent is a renaming

                  else
                     Set_Entity (Par, Cunit_Entity (Unump));
                  end if;
               end;
            end if;

         --  If the parent is not a renaming, then get its name (this may
         --  be different from the parent spec name obtained above because
         --  of renamings higher up in the hierarchy).

         else
            Uname_Actual := New_Child (Load_Name, Unit_Name (Unump));
         end if;

      --  Here if unit to be loaded is not a child unit

      else
         Uname_Actual := Load_Name;
      end if;

      Fname := Get_File_Name (Uname_Actual, Subunit);

      if Debug_Flag_L then
         Write_Eol;
         Write_Str ("*** Load request for unit: ");
         Write_Unit_Name (Load_Name);

         if Required then
            Write_Str (" (Required = True)");
         else
            Write_Str (" (Required = False)");
         end if;

         Write_Eol;

         if Uname_Actual /= Load_Name then
            Write_Str ("*** Actual unit loaded: ");
            Write_Unit_Name (Uname_Actual);
         end if;
      end if;

      --  Capture error location if it is for the main unit. The idea is to
      --  post errors on the main unit location, not the most recent unit.
      --  Note: Unit_Name (Main_Unit) is not set if we are parsing gnat.adc.

      if Present (Error_Node)
        and then Unit_Name (Main_Unit) /= No_Name
      then
         --  It seems like In_Extended_Main_Source_Unit (Error_Node) would
         --  do the trick here, but that's wrong, it is much too early to
         --  call this routine. We are still in the parser, and the required
         --  semantic information is not established yet. So we base the
         --  judgment on unit names.

         Get_External_Unit_Name_String (Unit_Name (Main_Unit));

         declare
            Main_Unit_Name : constant String := Name_Buffer (1 .. Name_Len);

         begin
            Get_External_Unit_Name_String
              (Unit_Name (Get_Source_Unit (Error_Node)));

            --  If the two names are identical, then for sure we are part
            --  of the extended main unit

            if Main_Unit_Name = Name_Buffer (1 .. Name_Len) then
               Load_Msg_Sloc := Sloc (Error_Node);

            --  If the load is called from a with_type clause, the error
            --  node is correct.

            elsif Nkind (Parent (Error_Node)) = N_With_Type_Clause then
               Load_Msg_Sloc := Sloc (Error_Node);

            --  Otherwise, check for the subunit case, and if so, consider
            --  we have a match if one name is a prefix of the other name.

            else
               if Nkind (Unit (Cunit (Main_Unit))) = N_Subunit
                    or else
                  Nkind (Unit (Cunit (Get_Source_Unit (Error_Node)))) =
                                                                N_Subunit
               then
                  Name_Len := Integer'Min (Name_Len, Main_Unit_Name'Length);

                  if Name_Buffer (1 .. Name_Len)
                        =
                     Main_Unit_Name (1 .. Name_Len)
                  then
                     Load_Msg_Sloc := Sloc (Error_Node);
                  end if;
               end if;
            end if;
         end;
      end if;

      --  If we are generating error messages, then capture calling unit

      if Present (Error_Node) then
         Calling_Unit := Get_Source_Unit (Error_Node);
      else
         Calling_Unit := No_Unit;
      end if;

      --  See if we already have an entry for this unit

      Unum := Main_Unit;

      while Unum <= Units.Last loop
         exit when Uname_Actual = Units.Table (Unum).Unit_Name;
         Unum := Unum + 1;
      end loop;

      --  Whether or not the entry was found, Unum is now the right value,
      --  since it is one more than Units.Last (i.e. the index of the new
      --  entry we will create) in the not found case.

      --  A special check is necessary in the unit not found case. If the unit
      --  is not found, but the file in which it lives has already been loaded,
      --  then we have the problem that the file does not contain the unit that
      --  is needed. We simply treat this as a file not found condition.

      --  We skip this test in multiple unit per file mode since in this
      --  case we can have multiple units from the same source file.

      if Unum > Units.Last and then Get_Unit_Index (Uname_Actual) = 0 then
         for J in Units.First .. Units.Last loop
            if Fname = Units.Table (J).Unit_File_Name then
               if Debug_Flag_L then
                  Write_Str ("  file does not contain unit, Unit_Number = ");
                  Write_Int (Int (Unum));
                  Write_Eol;
                  Write_Eol;
               end if;

               if Present (Error_Node) then
                  if Is_Predefined_File_Name (Fname) then
                     Error_Msg_Name_1 := Uname_Actual;
                     Error_Msg
                       ("% is not a language defined unit", Load_Msg_Sloc);
                  else
                     Error_Msg_Name_1 := Fname;
                     Error_Msg_Unit_1 := Uname_Actual;
                     Error_Msg
                       ("File{ does not contain unit$", Load_Msg_Sloc);
                  end if;

                  Write_Dependency_Chain;
                  return No_Unit;

               else
                  return No_Unit;
               end if;
            end if;
         end loop;
      end if;

      --  If we are proceeding with load, then make load stack entry,
      --  and indicate the kind of with_clause responsible for the load.

      Load_Stack.Increment_Last;
      Load_Stack.Table (Load_Stack.Last) := (Unum, From_Limited_With);

      --  Case of entry already in table

      if Unum <= Units.Last then

         --  Here is where we check for a circular dependency, which is
         --  an attempt to load a unit which is currently in the process
         --  of being loaded. We do *not* care about a circular chain that
         --  leads back to a body, because this kind of circular dependence
         --  legitimately occurs (e.g. two package bodies that contain
         --  inlined subprogram referenced by the other).

         --  Ada 2005 (AI-50217): We also ignore limited_with clauses, because
         --  their purpose is precisely to create legal circular structures.

         if Loading (Unum)
           and then (Is_Spec_Name (Units.Table (Unum).Unit_Name)
                       or else Acts_As_Spec (Units.Table (Unum).Cunit))
           and then (Nkind (Error_Node) /= N_With_Clause
                       or else not Limited_Present (Error_Node))
           and then not From_Limited_With_Chain (From_Limited_With)
         then
            if Debug_Flag_L then
               Write_Str ("  circular dependency encountered");
               Write_Eol;
            end if;

            if Present (Error_Node) then
               Error_Msg ("circular unit dependency", Load_Msg_Sloc);
               Write_Dependency_Chain;
            else
               Load_Stack.Decrement_Last;
            end if;

            return No_Unit;
         end if;

         if Debug_Flag_L then
            Write_Str ("  unit already in file table, Unit_Number = ");
            Write_Int (Int (Unum));
            Write_Eol;
         end if;

         Load_Stack.Decrement_Last;
         return Unum;

      --  Unit is not already in table, so try to open the file

      else
         if Debug_Flag_L then
            Write_Str ("  attempt unit load, Unit_Number = ");
            Write_Int (Int (Unum));
            Write_Eol;
         end if;

         Src_Ind := Load_Source_File (Fname);

         --  Make a partial entry in the file table, used even in the file not
         --  found case to print the dependency chain including the last entry

         Units.Increment_Last;
         Units.Table (Unum).Unit_Name := Uname_Actual;

         --  File was found

         if Src_Ind /= No_Source_File then
            Units.Table (Unum) := (
              Cunit           => Empty,
              Cunit_Entity    => Empty,
              Dependency_Num  => 0,
              Dynamic_Elab    => False,
              Error_Location  => Sloc (Error_Node),
              Expected_Unit   => Uname_Actual,
              Fatal_Error     => False,
              Generate_Code   => False,
              Has_RACW        => False,
              Ident_String    => Empty,
              Loading         => True,
              Main_Priority   => Default_Main_Priority,
              Munit_Index     => 0,
              Serial_Number   => 0,
              Source_Index    => Src_Ind,
              Unit_File_Name  => Fname,
              Unit_Name       => Uname_Actual,
              Version         => Source_Checksum (Src_Ind));

            --  Parse the new unit

            declare
               Save_Index : constant Nat := Multiple_Unit_Index;
            begin
               Multiple_Unit_Index := Get_Unit_Index (Uname_Actual);
               Units.Table (Unum).Munit_Index := Multiple_Unit_Index;
               Initialize_Scanner (Unum, Source_Index (Unum));
               Discard_List (Par (Configuration_Pragmas => False,
                                  From_Limited_With     => From_Limited_With));
               Multiple_Unit_Index := Save_Index;
               Set_Loading (Unum, False);
            end;

            --  If spec is irrelevant, then post errors and quit

            if Corr_Body /= No_Unit
              and then Spec_Is_Irrelevant (Unum, Corr_Body)
            then
               Error_Msg_Name_1 := Unit_File_Name (Corr_Body);
               Error_Msg
                 ("cannot compile subprogram in file {!",
                  Load_Msg_Sloc);
               Error_Msg_Name_1 := Unit_File_Name (Unum);
               Error_Msg
                 ("\incorrect spec in file { must be removed first!",
                  Load_Msg_Sloc);
               return No_Unit;
            end if;

            --  If loaded unit had a fatal error, then caller inherits it!

            if Units.Table (Unum).Fatal_Error
              and then Present (Error_Node)
            then
               Units.Table (Calling_Unit).Fatal_Error := True;
            end if;

            --  Remove load stack entry and return the entry in the file table

            Load_Stack.Decrement_Last;
            return Unum;

         --  Case of file not found

         else
            if Debug_Flag_L then
               Write_Str ("  file was not found, load failed");
               Write_Eol;
            end if;

            --  Generate message if unit required

            if Required and then Present (Error_Node) then
               if Is_Predefined_File_Name (Fname) then

                  --  This is a predefined library unit which is not present
                  --  in the run time. If a predefined unit is not available
                  --  it may very likely be the case that there is also pragma
                  --  Restriction forbidding its usage. This is typically the
                  --  case when building a configurable run time, where the
                  --  usage of certain run-time units units is restricted by
                  --  means of both the corresponding pragma Restriction (such
                  --  as No_Calendar), and by not including the unit. Hence,
                  --  we check whether this predefined unit is forbidden, so
                  --  that the message about the restriction violation is
                  --  generated, if needed.

                  Check_Restricted_Unit (Load_Name, Error_Node);

                  Error_Msg_Name_1 := Uname_Actual;
                  Error_Msg
                    ("% is not a predefined library unit", Load_Msg_Sloc);

               else
                  Error_Msg_Name_1 := Fname;
                  Error_Msg ("file{ not found", Load_Msg_Sloc);
               end if;

               Write_Dependency_Chain;

               --  Remove unit from stack, to avoid cascaded errors on
               --  subsequent missing files.

               Load_Stack.Decrement_Last;
               Units.Decrement_Last;

            --  If unit not required, remove load stack entry and the junk
            --  file table entry, and return No_Unit to indicate not found,

            else
               Load_Stack.Decrement_Last;
               Units.Decrement_Last;
            end if;

            return No_Unit;
         end if;
      end if;
   end Load_Unit;

   ------------------------
   -- Make_Instance_Unit --
   ------------------------

   --  If the unit is an instance, it appears as a package declaration, but
   --  contains both declaration and body of the instance. The body becomes
   --  the main unit of the compilation, and the declaration is inserted
   --  at the end of the unit table. The main unit now has the name of a
   --  body, which is constructed from the name of the original spec,
   --  and is attached to the compilation node of the original unit. The
   --  declaration has been attached to a new compilation unit node, and
   --  code will have to be generated for it.

   procedure Make_Instance_Unit (N : Node_Id) is
      Sind : constant Source_File_Index := Source_Index (Main_Unit);
   begin
      Units.Increment_Last;
      Units.Table (Units.Last)               := Units.Table (Main_Unit);
      Units.Table (Units.Last).Cunit         := Library_Unit (N);
      Units.Table (Units.Last).Generate_Code := True;
      Units.Table (Main_Unit).Cunit          := N;
      Units.Table (Main_Unit).Unit_Name      :=
        Get_Body_Name (Unit_Name (Get_Cunit_Unit_Number (Library_Unit (N))));
      Units.Table (Main_Unit).Version        := Source_Checksum (Sind);
   end Make_Instance_Unit;

   ------------------------
   -- Spec_Is_Irrelevant --
   ------------------------

   function Spec_Is_Irrelevant
     (Spec_Unit : Unit_Number_Type;
      Body_Unit : Unit_Number_Type) return Boolean
   is
      Sunit : constant Node_Id := Cunit (Spec_Unit);
      Bunit : constant Node_Id := Cunit (Body_Unit);

   begin
      --  The spec is irrelevant if the body is a subprogram body, and the
      --  spec is other than a subprogram spec or generic subprogram spec.
      --  Note that the names must be the same, we don't need to check that,
      --  because we already know that from the fact that the file names are
      --  the same.

      return
         Nkind (Unit (Bunit)) = N_Subprogram_Body
           and then Nkind (Unit (Sunit)) /= N_Subprogram_Declaration
           and then Nkind (Unit (Sunit)) /= N_Generic_Subprogram_Declaration;
   end Spec_Is_Irrelevant;

   --------------------
   -- Version_Update --
   --------------------

   procedure Version_Update (U : Node_Id; From : Node_Id) is
      Unum  : constant Unit_Number_Type := Get_Cunit_Unit_Number (U);
      Fnum  : constant Unit_Number_Type := Get_Cunit_Unit_Number (From);
   begin
      if Source_Index (Fnum) /= No_Source_File then
         Units.Table (Unum).Version :=
           Units.Table (Unum).Version
             xor
              Source_Checksum (Source_Index (Fnum));
      end if;
   end Version_Update;

   ----------------------------
   -- Write_Dependency_Chain --
   ----------------------------

   procedure Write_Dependency_Chain is
   begin
      --  The dependency chain is only written if it is at least two entries
      --  deep, otherwise it is trivial (the main unit depending on a unit
      --  that it obviously directly depends on).

      if Load_Stack.Last - 1 > Load_Stack.First then
         for U in Load_Stack.First .. Load_Stack.Last - 1 loop
            Error_Msg_Unit_1 :=
              Unit_Name (Load_Stack.Table (U).Unit_Number);
            Error_Msg_Unit_2 :=
              Unit_Name (Load_Stack.Table (U + 1).Unit_Number);
            Error_Msg ("$ depends on $!", Load_Msg_Sloc);
         end loop;
      end if;
   end Write_Dependency_Chain;

end Lib.Load;
