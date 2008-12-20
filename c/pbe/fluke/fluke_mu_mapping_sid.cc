/*
 * Copyright (c) 1997, 1998, 1999 The University of Utah and
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
#include <string.h>

#include <mom/c/libcast.h>

#include "fluke.h"

void fluke_mu_state::mu_mapping_sid(cast_expr cexpr, cast_type ctype,
				    mint_ref itype,
				    pres_c_mapping_sid *sid_map)
{
	/* Do the library thing, which only sets `mu_state' slots. */
	mem_mu_state::mu_mapping_sid(cexpr, ctype, itype, sid_map);
	
	/* Now do our special Fluke transport stuff. */
	switch (sid_map->kind) {
	case PRES_C_SID_CLIENT:
		if (op & MUST_ENCODE) {
			/* Only client stubs encode client SIDs. */
			assert(!strcmp(get_which_stub(), "client"));
			/*
			 * The code to make use of a client SID is generated by
			 * `w_client_stub'; nothing need be done here.
			 */

		} else if (op & MUST_DECODE) {
			/* Only server functions decode client SIDs. */
			assert(!strcmp(get_which_stub(), "server"));
			
			/* Get the SID out of the MOM dispatch data. */
			add_stmt(cast_new_stmt_expr(
				cast_new_expr_assign(
					cexpr,
					cast_new_expr_sel(
						cast_new_unary_expr(
							CAST_UNARY_DEREF,
							cast_new_expr_name(
							    "_dispatch_data"
								)),
						cast_new_scoped_name(
							"client_sid", NULL)))
				));
		}
		break;
		
	case PRES_C_SID_SERVER:
		/*
		 * As of December 1997, Flask no longer uses server SID stub
		 * parameters.  Warn if we try to process one.
		 */
		if ((op & MUST_ENCODE)
		    || (op & MUST_DECODE)) {
			warn("the Fluke transport does not support server SID "
			     "arguments to stubs.");
			warn("ignoring server SID parameter to %s stub.",
			     get_which_stub());
		}
		
#if 0
		if (op & MUST_ENCODE) {
			/* Only client stubs encode server SIDs. */
			assert(!strcmp(get_which_stub(), "client"));
			/*
			 * The code to make use of a server SID is generated by
			 * `w_client_stub'; nothing need be done here.
			 */
			
		} else if (op & MUST_DECODE) {
			/* Both clients and servers decode server SIDs. */
			
			if (!strcmp(get_which_stub(), "client"))
				/*
				 * Clients decode actual server SIDs.  The code
				 * for presenting the actual server SID is
				 * built by `w_client_stub'; nothing need be
				 * done here.
				 */
				break;
			
			if (strcmp(get_which_stub(), "server"))
				panic("In `fluke_mu_state::mu_mapping_sid', "
				      "generating neither client stub nor "
				      "server skeleton.");
			
			/*
			 * Servers decode client-required server SIDs.  Get the
			 * SID out of the MOM dispatch data.
			 */
			add_stmt(cast_new_stmt_expr(
				cast_new_expr_assign(
					cexpr,
					cast_new_expr_sel(
						cast_new_unary_expr(
							CAST_UNARY_DEREF,
							cast_new_expr_name(
							    "_dispatch_data"
								)),
						cast_new_scoped_name(
							"server_sid", NULL)))
				));
		}
#endif /* 0 */
		break;
		
	default:
		panic("In `fluke_mu_state::mu_mapping_sid', "
		      "unrecognized SID type %d.",
		      sid_map->kind);
		break;
	}
}

/* End of file. */

