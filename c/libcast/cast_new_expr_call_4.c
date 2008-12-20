/*
 * Copyright (c) 1997, 1998 The University of Utah and
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

cast_expr cast_new_expr_call_4(cast_expr func,
			       cast_expr p0, cast_expr p1, cast_expr p2,
			       cast_expr p3)
{
	cast_expr expr = cast_new_expr_call(func, 4);
	
	expr->cast_expr_u_u.call.params.cast_expr_array_val[0] = p0;
	expr->cast_expr_u_u.call.params.cast_expr_array_val[1] = p1;
	expr->cast_expr_u_u.call.params.cast_expr_array_val[2] = p2;
	expr->cast_expr_u_u.call.params.cast_expr_array_val[3] = p3;
	
	return expr;
}

/* End of file. */

