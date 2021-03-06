/* Language parser definitions for the GNU compiler for the Java(TM) language.
   Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004,
   2005, 2006, 2007 Free Software Foundation, Inc.
   Contributed by Alexandre Petit-Bianco (apbianco@cygnus.com)

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to
the Free Software Foundation, 51 Franklin Street, Fifth Floor,
Boston, MA 02110-1301, USA.

Java and all Java-based marks are trademarks or registered trademarks
of Sun Microsystems, Inc. in the United States and other countries.
The Free Software Foundation is independent of Sun Microsystems, Inc.  */

#ifndef GCC_JAVA_PARSE_H
#define GCC_JAVA_PARSE_H

/* Extern global variable declarations */
extern struct obstack temporary_obstack;
extern int quiet_flag;

#ifdef VERBOSE_SKELETON
#undef SOURCE_FRONTEND_DEBUG
#define SOURCE_FRONTEND_DEBUG(X)				\
  {if (!quiet_flag) {printf ("* "); printf X; putchar ('\n');} }
#else
#define SOURCE_FRONTEND_DEBUG(X)
#endif

/* Types classification, according to the JLS, section 4.2 */
#define JFLOAT_TYPE_P(TYPE)      (TYPE && TREE_CODE ((TYPE)) == REAL_TYPE)
#define JINTEGRAL_TYPE_P(TYPE)   ((TYPE) 				   \
				  && (TREE_CODE ((TYPE)) == INTEGER_TYPE))
#define JNUMERIC_TYPE_P(TYPE)    ((TYPE)				\
				  && (JFLOAT_TYPE_P ((TYPE))		\
				      || JINTEGRAL_TYPE_P ((TYPE))))
#define JPRIMITIVE_TYPE_P(TYPE)  ((TYPE) 				  \
				  && (JNUMERIC_TYPE_P ((TYPE))		  \
				  || TREE_CODE ((TYPE)) == BOOLEAN_TYPE))

/* Not defined in the LRM */
#define JSTRING_TYPE_P(TYPE) ((TYPE) 					   \
			      && ((TYPE) == string_type_node ||		   \
				  (TREE_CODE (TYPE) == POINTER_TYPE &&	   \
				   TREE_TYPE (TYPE) == string_type_node)))
#define JREFERENCE_TYPE_P(TYPE) ((TYPE)					      \
				 && (TREE_CODE (TYPE) == RECORD_TYPE 	      \
				     ||	(TREE_CODE (TYPE) == POINTER_TYPE     \
					 &&  TREE_CODE (TREE_TYPE (TYPE)) ==  \
					 RECORD_TYPE)))

int java_report_errors (void);
extern tree do_resolve_class (tree, tree, tree, tree, tree);

/* Always in use, no matter what you compile */
void java_push_parser_context (void);
void java_pop_parser_context (int);
extern void java_parser_context_save_global (void);
extern void java_parser_context_restore_global (void);

#endif /* ! GCC_JAVA_PARSE_H */
