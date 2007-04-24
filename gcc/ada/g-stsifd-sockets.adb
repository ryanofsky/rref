------------------------------------------------------------------------------
--                                                                          --
--                         GNAT COMPILER COMPONENTS                         --
--                                                                          --
--     G N A T . S O C K E T S . T H I N . S I G N A L L I N G _ F D S      --
--                                                                          --
--                                 B o d y                                  --
--                                                                          --
--                     Copyright (C) 2001-2006, AdaCore                     --
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
-- As a special exception,  if other files  instantiate  generics from this --
-- unit, or you link  this unit with other files  to produce an executable, --
-- this  unit  does not  by itself cause  the resulting  executable  to  be --
-- covered  by the  GNU  General  Public  License.  This exception does not --
-- however invalidate  any other reasons why  the executable file  might be --
-- covered by the  GNU Public License.                                      --
--                                                                          --
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

--  Portable sockets-based implementation of GNAT.Sockets.Thin.Signalling_Fds
--  used for platforms that do not support UNIX pipes.

--  Note: this code used to be in GNAT.Sockets, but has been moved to a
--  platform-specific file. It is now used only for non-UNIX platforms.

separate
  (GNAT.Sockets.Thin)
package body Signalling_Fds is

   ------------
   -- Create --
   ------------

   function Create (Fds : not null access Fd_Pair) return C.int is
      L_Sock, R_Sock, W_Sock : C.int := Failure;
      --  Listening socket, read socket and write socket

      Sin : aliased Sockaddr_In;
      Len : aliased C.int := Sin'Size / 8;
      --  Address of listening socket

      Res : C.int;
      --  Return status of system calls

      Err : Integer;
      --  Saved errno value

   begin
      Fds (Read_End)  := Failure;
      Fds (Write_End) := Failure;

      --  We open two signalling sockets. One of them is used to send data
      --  to the other, which is included in a C_Select socket set. The
      --  communication is used to force the call to C_Select to complete,
      --  and the waiting task to resume its execution.

      --  Create a listening socket

      L_Sock := C_Socket (Constants.AF_INET, Constants.SOCK_STREAM, 0);

      if L_Sock = Failure then
         goto Fail;
      end if;

      --  Bind the socket to an available port on localhost

      Sin.Sin_Addr.S_B1 := 127;
      Sin.Sin_Addr.S_B2 := 0;
      Sin.Sin_Addr.S_B3 := 0;
      Sin.Sin_Addr.S_B4 := 1;
      Sin.Sin_Port := 0;

      Res := C_Bind (L_Sock, Sin'Address, Len);

      if Res = Failure then
         goto Fail;
      end if;

      --  Get assigned port

      Res := C_Getsockname (L_Sock, Sin'Address, Len'Access);
      if Res = Failure then
         goto Fail;
      end if;

      --  Set socket to listen mode, with a backlog of 1 to guarantee that
      --  exactly one call to connect(2) succeeds.

      Res := C_Listen (L_Sock, 1);

      if Res = Failure then
         goto Fail;
      end if;

      --  Create read end (client) socket

      R_Sock := C_Socket (Constants.AF_INET, Constants.SOCK_STREAM, 0);

      if R_Sock = Failure then
         goto Fail;
      end if;

      --  Connect listening socket

      Res := C_Connect (R_Sock, Sin'Address, Len);

      if Res = Failure then
         goto Fail;
      end if;

      --  Since the call to connect(2) has suceeded and the backlog limit on
      --  the listening socket is 1, we know that there is now exactly one
      --  pending connection on L_Sock, which is the one from R_Sock.

      W_Sock := C_Accept (L_Sock, Sin'Address, Len'Access);
      if W_Sock = Failure then
         goto Fail;
      end if;

      --  Set TCP_NODELAY on W_Sock, since we always want to send the data out
      --  immediately.

      Set_Socket_Option
        (Socket => Socket_Type (W_Sock),
         Level  => IP_Protocol_For_TCP_Level,
         Option => (Name => No_Delay, Enabled => True));

      --  Close listening socket (ignore exit status)

      Res := C_Close (L_Sock);

      Fds (Read_End)  := R_Sock;
      Fds (Write_End) := W_Sock;

      return Success;

   <<Fail>>
      Err := Socket_Errno;

      if W_Sock /= Failure then
         Res := C_Close (W_Sock);
      end if;

      if R_Sock /= Failure then
         Res := C_Close (R_Sock);
      end if;

      if L_Sock /= Failure then
         Res := C_Close (L_Sock);
      end if;

      Set_Socket_Errno (Err);

      return Failure;
   end Create;

   ----------
   -- Read --
   ----------

   function Read (Rsig : C.int) return C.int is
      Buf : aliased Character;
   begin
      return C_Recv (Rsig, Buf'Address, 1, Constants.MSG_Forced_Flags);
   end Read;

   -----------
   -- Write --
   -----------

   function Write (Wsig : C.int) return C.int is
      Buf : aliased Character := ASCII.NUL;
   begin
      return C_Send (Wsig, Buf'Address, 1, Constants.MSG_Forced_Flags);
   end Write;

end Signalling_Fds;
