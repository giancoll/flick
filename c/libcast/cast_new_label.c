/*
 * Copyright (c) 1998, 1999 The University of Utah and
 * the Computer Systems Laboratory at the University of Utah (CSL).
 *
 * This file is part of Flick, the Flexible IDL Compiler Kit.
 *
 * Flick is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Flick is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Flick; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place #330, Boston, MA 02111, USA.
 */

#include <mom/compiler.h>
#include <mom/c/libcast.h>

cast_stmt cast_new_label(const char *name, cast_stmt stmt)
{
	cast_stmt new_stmt = cast_new_stmt(CAST_STMT_LABEL);
	new_stmt->cast_stmt_u_u.s_label.label = ir_strlit(name);
	new_stmt->cast_stmt_u_u.s_label.stmt = stmt;
	new_stmt->cast_stmt_u_u.s_label.users = 0;
	return new_stmt;
}

/* End of file. */

