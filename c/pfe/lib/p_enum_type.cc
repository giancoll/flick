/*
 * Copyright (c) 1995, 1996, 1997, 1998, 1999 The University of Utah and
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

#include <mom/c/libcast.h>
#include <mom/c/libpres_c.h>

#include "private.hh"

void pg_state::p_enum_type(aoi_enum *ae,
			   p_type_collection **out_ptc)
{
	p_type_collection *ptc;
	p_type_node *ptn;
	cast_type ctype;
	cast_enum_type *et;
	char *enum_name;
	
	int curval;
	
	/*****/
	
	enum_name = calc_enum_tag_name(ae->enum_label);
	ctype = cast_new_type(CAST_TYPE_ENUM);
	et = &(ctype->cast_type_u_u.enum_type);
	et->name = cast_new_scoped_name(enum_name, NULL);
	
	ptc = p_new_type_collection(enum_name);
	ptn = new p_type_node;
	ptn->set_flags(enum_type_node_flags);
	ptn->set_name("definition");
	ptn->set_format("%s");
	ptn->set_type(ctype);
	ptn->set_mapping(pres_c_new_mapping(PRES_C_MAPPING_DIRECT));
	ptc->add_type("default", ptn);
	
	et->slots.slots_len = ae->defs.defs_len;
	et->slots.slots_val = (cast_enum_field *)
			      mustmalloc(sizeof(cast_enum_field)
					 * ae->defs.defs_len);
	
	curval = 0;
	for (unsigned int i = 0; i < et->slots.slots_len; i++) {
		et->slots.slots_val[i].name =
			calc_enum_member_name(ae->defs.defs_val[i].name);
		
		if (ae->defs.defs_val[i].type->kind != AOI_CONST)
			et->slots.slots_val[i].val =
				cast_new_expr_lit_int(curval,
						      (CAST_MOD_SIGNED
						       | CAST_MOD_LONG));
		else {
			et->slots.slots_val[i].val =
				p_const_translate(&ae->defs.defs_val[i].type->
						  aoi_type_u_u.const_def);
			curval = ae->defs.defs_val[i].type->
				 aoi_type_u_u.const_def.value->aoi_const_u_u.
				 const_int;
		}
		curval++;
	}
	
	if( *out_ptc )
		(*out_ptc)->set_collection_ref(ptc);
	else
		*out_ptc = ptc;
}

/* End of file. */

