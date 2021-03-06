/*
 * Copyright (c) 1999 The University of Utah and
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
#include <mom/libaoi.h>
#include <mom/c/libcast.h>
#include <mom/c/libpres_c.h>

#include <mom/c/pg_corbaxx.hh>

void pg_corbaxx::p_type_tag_type(p_type_collection **out_ptc)
{
	/*
	 * We should only get here if we have an `AOI_TYPE_TAG' that is not in
	 * the `tag' field of a containing `AOI_TYPED'.  (See `p_typed_type'.)
	 *
	 * In other words, if we get here, we had a `CORBA::TypeCode' in the
	 * original IDL.
	 */
	
	/*
	 * Return the precomputed type collection from `prim_collections'.
	 */
	if (*out_ptc)
		(*out_ptc)->set_collection_ref(
			prim_collections[PRIM_COLLECTION_TYPE_TAG]
			);
	else
		*out_ptc = prim_collections[PRIM_COLLECTION_TYPE_TAG];
}

/* End of file. */

