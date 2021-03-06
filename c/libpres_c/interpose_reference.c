/*
 * Copyright (c) 1998 The University of Utah and
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

#include <assert.h>
#include <mom/c/libcast.h>
#include <mom/c/libpres_c.h>

void pres_c_interpose_var_reference(cast_type *inout_ctype,
				    pres_c_mapping *inout_mapping)
{
	pres_c_mapping old_mapping, new_mapping;
	
	assert(inout_mapping); assert(*inout_mapping);
	
	if (inout_ctype) {
		cast_type old_ctype, new_ctype;
		
		assert(*inout_ctype);
		old_ctype = *inout_ctype;
		new_ctype = cast_new_reference_type(old_ctype);
		*inout_ctype = new_ctype;
	}
	
	old_mapping = *inout_mapping;
	new_mapping = pres_c_new_mapping(PRES_C_MAPPING_VAR_REFERENCE);
	new_mapping->pres_c_mapping_u_u.var_ref.target = old_mapping;
	*inout_mapping = new_mapping;
}

