/* Core target definitions for GNU compiler
   for IBM RS/6000 PowerPC targeted to embedded ELF systems.
   Copyright (C) 1995, 1996, 2000, 2003, 2004, 2007 Free Software Foundation, Inc.
   Contributed by Cygnus Support.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 2, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING.  If not, write to the
   Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.  */

/* Add -meabi to target flags.  */
#undef TARGET_DEFAULT
#define TARGET_DEFAULT (MASK_POWERPC | MASK_NEW_MNEMONICS | MASK_EABI)

/* Invoke an initializer function to set up the GOT.  */
#define NAME__MAIN "__eabi"
#define INVOKE__main

#undef TARGET_VERSION
#define TARGET_VERSION fprintf (stderr, " (PowerPC Embedded)");

#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()          \
  do                                      \
    {                                     \
      builtin_define_std ("PPC");         \
      builtin_define ("__embedded__");    \
      builtin_assert ("system=embedded"); \
      builtin_assert ("cpu=powerpc");     \
      builtin_assert ("machine=powerpc"); \
      TARGET_OS_SYSV_CPP_BUILTINS ();     \
    }                                     \
  while (0)
