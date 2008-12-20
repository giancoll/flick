/*
 * Copyright (c) 1997 The University of Utah and
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

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <mom/c/libcast.h>
#include "iiop.h"

void iiop_mu_state::mu_prefix_params() 
{
	/*
	 * In IIOP, a `Principal' pseudo object comes between the operation
	 * discriminator and the operation parameters in the request header.
	 * (See Section 12.4.1 of the CORBA 2.0 specification.)  This pseudo
	 * object is encoded as an octet sequence (Section 12.3.4) and has no
	 * meaning for us (yet).
	 */
	
	if ((op & MUST_ENCODE) &&
	    (op & MUST_REQUEST)) {
		if (!strcmp(which_stub, "msg")) {
			/*
			 * Encode a 8-byte-length octet sequence in the
			 * request, to be filled in by the runtime.
			 */
			cast_stmt comment = cast_new_stmt(CAST_STMT_TEXT);
			
			comment->cast_stmt_u_u.text
				= flick_asprintf("/* Leave space for the "
						 "requesting `Principal' "
						 "pseudo object "
						 "(client ID). */");
			
			add_stmt(comment);
			
			/* Length of principal */
			cast_expr cexpr_eight
				= cast_new_expr_lit_int(8, CAST_MOD_UNSIGNED);
			cast_type ctype_ulong
				= cast_new_prim_type(CAST_PRIM_INT,
						     CAST_MOD_UNSIGNED);
			
			mu_mapping_simple(cexpr_eight,
					  ctype_ulong,
					  (pres->mint.standard_refs.
					   unsigned32_ref));
			
			/* save the spot where the principal lives */
			principal_mark = chunk_size;

			cast_expr cexpr_zero
				= cast_new_expr_lit_int(0, CAST_MOD_UNSIGNED);
			
			/* Leave space for the runtime */
			mu_mapping_simple(cexpr_zero,
					  ctype_ulong,
					  (pres->mint.standard_refs.
					   unsigned32_ref));
			mu_mapping_simple(cexpr_zero,
					  ctype_ulong,
					  (pres->mint.standard_refs.
					   unsigned32_ref));
		} else {
			/*
			 * Encode a zero-length octet sequence in the request.
			 */
			cast_stmt comment = cast_new_stmt(CAST_STMT_TEXT);
			
			comment->cast_stmt_u_u.text
				= flick_asprintf("/* Encode the requesting "
						 "`Principal' pseudo object "
						 "(client ID). */");
			
			add_stmt(comment);
			
			cast_expr cexpr_zero
				= cast_new_expr_lit_int(0, CAST_MOD_UNSIGNED);
			cast_type ctype_ulong
				= cast_new_prim_type(CAST_PRIM_INT,
						     CAST_MOD_UNSIGNED);
			
			mu_mapping_simple(cexpr_zero,
					  ctype_ulong,
					  (pres->mint.standard_refs.
					   unsigned32_ref));
		}
	}
	
	if ((op & MUST_DECODE) &&
	    (op & MUST_REQUEST)) {
		/*
		 * Decode an arbitrary `Principal' octet sequence on the server
		 * side.  Usually we'll be talking to a standard Flick-
		 * generated client with a zero-length `Principal'; however we
		 * may be talking to a decomposed-style Flick-generated client
		 * giving us it's client pseudo-object, or possibly a client
		 * generated by some other compiler.
		 */
		cast_type ctype_ulong
			= cast_new_prim_type(CAST_PRIM_INT, CAST_MOD_UNSIGNED);
		cast_expr cexpr_principal_len
			= add_temp_var("principal_len", ctype_ulong);
		
		cast_stmt comment = cast_new_stmt(CAST_STMT_TEXT);
		
		cast_expr *principal_glob_size_expr;
		cast_expr *principal_chunk_size_expr;
		
		/*****/
		
		comment->cast_stmt_u_u.text =
			flick_asprintf("/* Decode the requesting "
				       "`Principal' pseudo object "
				       "(client ID). */");
		add_stmt(comment);
		
		mu_mapping_simple(cexpr_principal_len,
				  ctype_ulong,
				  pres->mint.standard_refs.unsigned32_ref);
		/*
		 * We have to break the current glob; the Principal sequence
		 * can be arbitrarily long.
		 */
		break_glob();
		
#if 0
		/*
		 * Let the runtime handle the client pseudo object.
		 * Note that we still may be talking to a regular Flick client
		 * or a client generated from another compiler.
		 * WE MAY NOT HAVE THE PSEUDO OBJECT!
		 */
		if (!strcmp(which_stub, "msg")) {
			cast_stmt call
				= cast_new_stmt_expr(cast_new_expr_call_1(
					flick_asprintf("flick_%s_%s_"
						       "decode_principal",
						       get_be_name(),
						       which_stub);
					cexpr_principal_len));
			add_stmt(call);
		}
#endif
		
		/* We need to manually add a check span here
		   since the stuff below tampers with chunks */
		if( current_span ) {
			struct mu_msg_span *mms;
			
			mms = new mu_msg_span;
			mms->set_block(c_block);
			mms->set_abort(abort_block);
			mms->begin();
			mms->set_size(cexpr_principal_len);
			mms->end();
			current_span->add_child(mms);
		}
		new_glob();
		new_chunk();
		/*
		 * Save the size expressions; we need to mangle them after
		 * `end_chunk/end_glob' and insert a reference to the length of
		 * the `Principal' sequence.
		 */
		principal_glob_size_expr = glob_size_expr;
		principal_chunk_size_expr = chunk_size_expr;
		end_chunk();
		end_glob();
		
		/* Fix the glob and chunk size expressions. */
		(*principal_glob_size_expr) = cexpr_principal_len;
		(*principal_chunk_size_expr) = cexpr_principal_len;
		
		/*
		 * Fix our memory alignment state.  The `mu_state' probably
		 * thinks that we are 4-byte aligned at this point (following
		 * a 4-byte aligned integer and a zero-byte chunk), but we
		 * really aren't.  We're only 1-byte aligned after skipping
		 * over the `Principal' octet sequence.
		 */
		max_msg_size = MAXUINT_MAX;
		align_bits = 0;
		align_ofs = 0;
	}
	
	mem_mu_state::mu_prefix_params();
}

/* End of file. */
