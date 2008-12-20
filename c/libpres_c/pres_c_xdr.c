#include <mom/pres_c.h>
/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <rpc/rpc.h>

bool_t
xdr_cast_ref(xdrs, objp)
	register XDR *xdrs;
	cast_ref *objp;
{

	if (!xdr_int(xdrs, objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline *objp;
{

	if (!xdr_pointer(xdrs, (char **)objp, sizeof (struct pres_c_inline_u), (xdrproc_t) xdr_pres_c_inline_u))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping *objp;
{

	if (!xdr_pointer(xdrs, (char **)objp, sizeof (struct pres_c_mapping_u), (xdrproc_t) xdr_pres_c_mapping_u))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_alloc_flags(xdrs, objp)
	register XDR *xdrs;
	pres_c_alloc_flags *objp;
{

	if (!xdr_u_int(xdrs, objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_allocator_kind(xdrs, objp)
	register XDR *xdrs;
	pres_c_allocator_kind *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_allocator(xdrs, objp)
	register XDR *xdrs;
	pres_c_allocator *objp;
{

	if (!xdr_pres_c_allocator_kind(xdrs, &objp->kind))
		return (FALSE);
	switch (objp->kind) {
	case PRES_C_ALLOCATOR_DONTCARE:
		break;
	case PRES_C_ALLOCATOR_STATIC:
		break;
	case PRES_C_ALLOCATOR_OUTOFLINE:
		if (!xdr_string(xdrs, &objp->pres_c_allocator_u.ool_name, ~0))
			return (FALSE);
		break;
	case PRES_C_ALLOCATOR_NAME:
		if (!xdr_string(xdrs, &objp->pres_c_allocator_u.name, ~0))
			return (FALSE);
		break;
	default:
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_pres_c_allocation_case(xdrs, objp)
	register XDR *xdrs;
	pres_c_allocation_case *objp;
{

	if (!xdr_pres_c_alloc_flags(xdrs, &objp->flags))
		return (FALSE);
	if (!xdr_pres_c_allocator(xdrs, &objp->allocator))
		return (FALSE);
	if (!xdr_cast_init(xdrs, &objp->alloc_init))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_allocation_allow(xdrs, objp)
	register XDR *xdrs;
	pres_c_allocation_allow *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_allocation_u(xdrs, objp)
	register XDR *xdrs;
	pres_c_allocation_u *objp;
{

	if (!xdr_pres_c_allocation_allow(xdrs, &objp->allow))
		return (FALSE);
	switch (objp->allow) {
	case PRES_C_ALLOCATION_ALLOW:
		if (!xdr_pres_c_allocation_case(xdrs, &objp->pres_c_allocation_u_u.val))
			return (FALSE);
		break;
	case PRES_C_ALLOCATION_INVALID:
		break;
	default:
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_pres_c_allocation(xdrs, objp)
	register XDR *xdrs;
	pres_c_allocation *objp;
{

	if (!xdr_vector(xdrs, (char *)objp->cases, PRES_C_DIRECTIONS,
		sizeof (pres_c_allocation_u), (xdrproc_t) xdr_pres_c_allocation_u))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_allocation_owner(xdrs, objp)
	register XDR *xdrs;
	allocation_owner *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_temporary_type(xdrs, objp)
	register XDR *xdrs;
	pres_c_temporary_type *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_temporary(xdrs, objp)
	register XDR *xdrs;
	pres_c_temporary *objp;
{

	if (!xdr_pres_c_mapping(xdrs, &objp->map))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->name, ~0))
		return (FALSE);
	if (!xdr_cast_type(xdrs, &objp->ctype))
		return (FALSE);
	if (!xdr_cast_expr(xdrs, &objp->init))
		return (FALSE);
	if (!xdr_pres_c_temporary_type(xdrs, &objp->type))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->is_const))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->prehandler, ~0))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->posthandler, ~0))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_index(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_index *objp;
{

	if (!xdr_int(xdrs, objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_atom(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_atom *objp;
{

	if (!xdr_pres_c_inline_index(xdrs, &objp->index))
		return (FALSE);
	if (!xdr_pres_c_mapping(xdrs, &objp->mapping))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_struct_slot(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_struct_slot *objp;
{

	if (!xdr_int(xdrs, &objp->mint_struct_slot_index))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->inl))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_struct(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_struct *objp;
{

	if (!xdr_array(xdrs, (char **)&objp->slots.slots_val, (u_int *) &objp->slots.slots_len, ~0,
		sizeof (pres_c_inline_struct_slot), (xdrproc_t) xdr_pres_c_inline_struct_slot))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_func_params_struct(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_func_params_struct *objp;
{

	if (!xdr_array(xdrs, (char **)&objp->slots.slots_val, (u_int *) &objp->slots.slots_len, ~0,
		sizeof (pres_c_inline_struct_slot), (xdrproc_t) xdr_pres_c_inline_struct_slot))
		return (FALSE);
	if (!xdr_pointer(xdrs, (char **)&objp->return_slot, sizeof (pres_c_inline_struct_slot), (xdrproc_t) xdr_pres_c_inline_struct_slot))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_handler_func(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_handler_func *objp;
{

	if (!xdr_array(xdrs, (char **)&objp->slots.slots_val, (u_int *) &objp->slots.slots_len, ~0,
		sizeof (pres_c_inline_struct_slot), (xdrproc_t) xdr_pres_c_inline_struct_slot))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_struct_union_case(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_struct_union_case *objp;
{

	if (!xdr_int(xdrs, &objp->index))
		return (FALSE);
	if (!xdr_pres_c_mapping(xdrs, &objp->mapping))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_struct_union(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_struct_union *objp;
{

	if (!xdr_pres_c_inline_atom(xdrs, &objp->discrim))
		return (FALSE);
	if (!xdr_pres_c_inline_index(xdrs, &objp->union_index))
		return (FALSE);
	if (!xdr_array(xdrs, (char **)&objp->cases.cases_val, (u_int *) &objp->cases.cases_len, ~0,
		sizeof (pres_c_inline_struct_union_case), (xdrproc_t) xdr_pres_c_inline_struct_union_case))
		return (FALSE);
	if (!xdr_pointer(xdrs, (char **)&objp->dfault, sizeof (pres_c_inline_struct_union_case), (xdrproc_t) xdr_pres_c_inline_struct_union_case))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_void_union_case(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_void_union_case *objp;
{

	if (!xdr_cast_expr(xdrs, &objp->case_value))
		return (FALSE);
	if (!xdr_cast_type(xdrs, &objp->type))
		return (FALSE);
	if (!xdr_pres_c_mapping(xdrs, &objp->mapping))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_void_union(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_void_union *objp;
{

	if (!xdr_pres_c_inline_atom(xdrs, &objp->discrim))
		return (FALSE);
	if (!xdr_pres_c_inline_index(xdrs, &objp->void_index))
		return (FALSE);
	if (!xdr_array(xdrs, (char **)&objp->cases.cases_val, (u_int *) &objp->cases.cases_len, ~0,
		sizeof (pres_c_inline_void_union_case), (xdrproc_t) xdr_pres_c_inline_void_union_case))
		return (FALSE);
	if (!xdr_pointer(xdrs, (char **)&objp->dfault, sizeof (pres_c_inline_void_union_case), (xdrproc_t) xdr_pres_c_inline_void_union_case))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_expanded_union(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_expanded_union *objp;
{

	if (!xdr_pres_c_inline_atom(xdrs, &objp->discrim))
		return (FALSE);
	if (!xdr_array(xdrs, (char **)&objp->cases.cases_val, (u_int *) &objp->cases.cases_len, ~0,
		sizeof (pres_c_inline), (xdrproc_t) xdr_pres_c_inline))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->dfault))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_collapsed_union(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_collapsed_union *objp;
{

	if (!xdr_mint_const(xdrs, &objp->discrim_val))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->selected_case))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_virtual_union_case(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_virtual_union_case *objp;
{

	if (!xdr_pres_c_inline(xdrs, objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_virtual_union(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_virtual_union *objp;
{

	if (!xdr_string(xdrs, &objp->arglist_name, ~0))
		return (FALSE);
	if (!xdr_pres_c_inline_virtual_union_case(xdrs, &objp->discrim))
		return (FALSE);
	if (!xdr_array(xdrs, (char **)&objp->cases.cases_val, (u_int *) &objp->cases.cases_len, ~0,
		sizeof (pres_c_inline_virtual_union_case), (xdrproc_t) xdr_pres_c_inline_virtual_union_case))
		return (FALSE);
	if (!xdr_pres_c_inline_virtual_union_case(xdrs, &objp->dfault))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_typed(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_typed *objp;
{

	if (!xdr_pres_c_inline(xdrs, &objp->tag))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->inl))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_allocation_context(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_allocation_context *objp;
{

	if (!xdr_string(xdrs, &objp->arglist_name, ~0))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->offset))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->length))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->min_len))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->max_len))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->alloc_len))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->min_alloc_len))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->max_alloc_len))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->release))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->terminator))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->mustcopy))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->overwrite))
		return (FALSE);
	if (!xdr_allocation_owner(xdrs, &objp->owner))
		return (FALSE);
	if (!xdr_pres_c_allocation(xdrs, &objp->alloc))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->ptr))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_xlate(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_xlate *objp;
{

	if (!xdr_pres_c_inline(xdrs, &objp->sub))
		return (FALSE);
	if (!xdr_pres_c_inline_index(xdrs, &objp->index))
		return (FALSE);
	if (!xdr_cast_type(xdrs, &objp->internal_ctype))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->translator, ~0))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->destructor, ~0))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_assign(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_assign *objp;
{

	if (!xdr_pres_c_inline(xdrs, &objp->sub))
		return (FALSE);
	if (!xdr_pres_c_inline_index(xdrs, &objp->index))
		return (FALSE);
	if (!xdr_cast_expr(xdrs, &objp->value))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_cond(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_cond *objp;
{

	if (!xdr_pres_c_inline_index(xdrs, &objp->index))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->true_inl))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->false_inl))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_message_attribute_kind(xdrs, objp)
	register XDR *xdrs;
	pres_c_message_attribute_kind *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_message_attribute(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_message_attribute *objp;
{

	if (!xdr_pres_c_message_attribute_kind(xdrs, &objp->kind))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_kind(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_kind *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_inline_u(xdrs, objp)
	register XDR *xdrs;
	pres_c_inline_u *objp;
{

	if (!xdr_pres_c_inline_kind(xdrs, &objp->kind))
		return (FALSE);
	switch (objp->kind) {
	case PRES_C_INLINE_ATOM:
		if (!xdr_pres_c_inline_atom(xdrs, &objp->pres_c_inline_u_u.atom))
			return (FALSE);
		break;
	case PRES_C_INLINE_STRUCT:
		if (!xdr_pres_c_inline_struct(xdrs, &objp->pres_c_inline_u_u.struct_i))
			return (FALSE);
		break;
	case PRES_C_INLINE_FUNC_PARAMS_STRUCT:
		if (!xdr_pres_c_inline_func_params_struct(xdrs, &objp->pres_c_inline_u_u.func_params_i))
			return (FALSE);
		break;
	case PRES_C_INLINE_HANDLER_FUNC:
		if (!xdr_pres_c_inline_handler_func(xdrs, &objp->pres_c_inline_u_u.handler_i))
			return (FALSE);
		break;
	case PRES_C_INLINE_STRUCT_UNION:
		if (!xdr_pres_c_inline_struct_union(xdrs, &objp->pres_c_inline_u_u.struct_union))
			return (FALSE);
		break;
	case PRES_C_INLINE_EXPANDED_UNION:
		if (!xdr_pres_c_inline_expanded_union(xdrs, &objp->pres_c_inline_u_u.expanded_union))
			return (FALSE);
		break;
	case PRES_C_INLINE_VOID_UNION:
		if (!xdr_pres_c_inline_void_union(xdrs, &objp->pres_c_inline_u_u.void_union))
			return (FALSE);
		break;
	case PRES_C_INLINE_COLLAPSED_UNION:
		if (!xdr_pres_c_inline_collapsed_union(xdrs, &objp->pres_c_inline_u_u.collapsed_union))
			return (FALSE);
		break;
	case PRES_C_INLINE_VIRTUAL_UNION:
		if (!xdr_pres_c_inline_virtual_union(xdrs, &objp->pres_c_inline_u_u.virtual_union))
			return (FALSE);
		break;
	case PRES_C_INLINE_TYPED:
		if (!xdr_pres_c_inline_typed(xdrs, &objp->pres_c_inline_u_u.typed))
			return (FALSE);
		break;
	case PRES_C_INLINE_THROWAWAY:
		break;
	case PRES_C_INLINE_XLATE:
		if (!xdr_pres_c_inline_xlate(xdrs, &objp->pres_c_inline_u_u.xlate))
			return (FALSE);
		break;
	case PRES_C_INLINE_ASSIGN:
		if (!xdr_pres_c_inline_assign(xdrs, &objp->pres_c_inline_u_u.assign))
			return (FALSE);
		break;
	case PRES_C_INLINE_COND:
		if (!xdr_pres_c_inline_cond(xdrs, &objp->pres_c_inline_u_u.cond))
			return (FALSE);
		break;
	case PRES_C_INLINE_MESSAGE_ATTRIBUTE:
		if (!xdr_pres_c_inline_message_attribute(xdrs, &objp->pres_c_inline_u_u.msg_attr))
			return (FALSE);
		break;
	case PRES_C_INLINE_ALLOCATION_CONTEXT:
		if (!xdr_pres_c_inline_allocation_context(xdrs, &objp->pres_c_inline_u_u.acontext))
			return (FALSE);
		break;
	case PRES_C_INLINE_TEMPORARY:
		if (!xdr_pres_c_temporary(xdrs, &objp->pres_c_inline_u_u.temp))
			return (FALSE);
		break;
	case PRES_C_INLINE_ILLEGAL:
		break;
	default:
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_stub(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_stub *objp;
{

	if (!xdr_int(xdrs, &objp->mapping_stub_index))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_direction(xdrs, objp)
	register XDR *xdrs;
	pres_c_direction *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_direction(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_direction *objp;
{

	if (!xdr_pres_c_direction(xdrs, &objp->dir))
		return (FALSE);
	if (!xdr_pres_c_mapping(xdrs, &objp->mapping))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_pointer(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_pointer *objp;
{

	if (!xdr_string(xdrs, &objp->arglist_name, ~0))
		return (FALSE);
	if (!xdr_pres_c_mapping(xdrs, &objp->target))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_var_reference(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_var_reference *objp;
{

	if (!xdr_pres_c_mapping(xdrs, &objp->target))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_optional_pointer(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_optional_pointer *objp;
{

	if (!xdr_string(xdrs, &objp->arglist_name, ~0))
		return (FALSE);
	if (!xdr_pres_c_mapping(xdrs, &objp->target))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_struct(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_struct *objp;
{

	if (!xdr_pres_c_inline(xdrs, objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_internal_array(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_internal_array *objp;
{

	if (!xdr_string(xdrs, &objp->arglist_name, ~0))
		return (FALSE);
	if (!xdr_pres_c_mapping(xdrs, &objp->element_mapping))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_flat_union(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_flat_union *objp;
{

	if (!xdr_pres_c_mapping(xdrs, &objp->discrim))
		return (FALSE);
	if (!xdr_array(xdrs, (char **)&objp->cases.cases_val, (u_int *) &objp->cases.cases_len, ~0,
		sizeof (pres_c_mapping), (xdrproc_t) xdr_pres_c_mapping))
		return (FALSE);
	if (!xdr_pres_c_mapping(xdrs, &objp->dfault))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_special(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_special *objp;
{

	if (!xdr_string(xdrs, &objp->marshaler_name, ~0))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_xlate(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_xlate *objp;
{

	if (!xdr_cast_type(xdrs, &objp->internal_ctype))
		return (FALSE);
	if (!xdr_pres_c_mapping(xdrs, &objp->internal_mapping))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->translator, ~0))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->destructor, ~0))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_reference_kind(xdrs, objp)
	register XDR *xdrs;
	pres_c_reference_kind *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_reference(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_reference *objp;
{

	if (!xdr_pres_c_reference_kind(xdrs, &objp->kind))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->ref_count))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->arglist_name, ~0))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_sid_kind(xdrs, objp)
	register XDR *xdrs;
	pres_c_sid_kind *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_sid(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_sid *objp;
{

	if (!xdr_pres_c_sid_kind(xdrs, &objp->kind))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_message_attribute(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_message_attribute *objp;
{

	if (!xdr_pres_c_message_attribute_kind(xdrs, &objp->kind))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_argument(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_argument *objp;
{

	if (!xdr_string(xdrs, &objp->arglist_name, ~0))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->arg_name, ~0))
		return (FALSE);
	if (!xdr_pres_c_mapping(xdrs, &objp->map))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_initialize(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_initialize *objp;
{

	if (!xdr_cast_expr(xdrs, &objp->value))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_selector(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_selector *objp;
{

	if (!xdr_int(xdrs, &objp->index))
		return (FALSE);
	if (!xdr_pres_c_mapping(xdrs, &objp->mapping))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_param_root(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_param_root *objp;
{

	if (!xdr_cast_type(xdrs, &objp->ctype))
		return (FALSE);
	if (!xdr_cast_init(xdrs, &objp->init))
		return (FALSE);
	if (!xdr_pres_c_mapping(xdrs, &objp->map))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_singleton(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_singleton *objp;
{

	if (!xdr_pres_c_inline(xdrs, &objp->inl))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_kind(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_kind *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_mapping_u(xdrs, objp)
	register XDR *xdrs;
	pres_c_mapping_u *objp;
{

	if (!xdr_pres_c_mapping_kind(xdrs, &objp->kind))
		return (FALSE);
	switch (objp->kind) {
	case PRES_C_MAPPING_DIRECT:
		break;
	case PRES_C_MAPPING_STUB:
		if (!xdr_pres_c_mapping_stub(xdrs, &objp->pres_c_mapping_u_u.mapping_stub))
			return (FALSE);
		break;
	case PRES_C_MAPPING_POINTER:
		if (!xdr_pres_c_mapping_pointer(xdrs, &objp->pres_c_mapping_u_u.pointer))
			return (FALSE);
		break;
	case PRES_C_MAPPING_INTERNAL_ARRAY:
		if (!xdr_pres_c_mapping_internal_array(xdrs, &objp->pres_c_mapping_u_u.internal_array))
			return (FALSE);
		break;
	case PRES_C_MAPPING_STRUCT:
		if (!xdr_pres_c_mapping_struct(xdrs, &objp->pres_c_mapping_u_u.struct_i))
			return (FALSE);
		break;
	case PRES_C_MAPPING_FLAT_UNION:
		if (!xdr_pres_c_mapping_flat_union(xdrs, &objp->pres_c_mapping_u_u.flat_union))
			return (FALSE);
		break;
	case PRES_C_MAPPING_SPECIAL:
		if (!xdr_pres_c_mapping_special(xdrs, &objp->pres_c_mapping_u_u.special))
			return (FALSE);
		break;
	case PRES_C_MAPPING_XLATE:
		if (!xdr_pres_c_mapping_xlate(xdrs, &objp->pres_c_mapping_u_u.xlate))
			return (FALSE);
		break;
	case PRES_C_MAPPING_REFERENCE:
		if (!xdr_pres_c_mapping_reference(xdrs, &objp->pres_c_mapping_u_u.ref))
			return (FALSE);
		break;
	case PRES_C_MAPPING_TYPE_TAG:
		break;
	case PRES_C_MAPPING_TYPED:
		break;
	case PRES_C_MAPPING_OPTIONAL_POINTER:
		if (!xdr_pres_c_mapping_optional_pointer(xdrs, &objp->pres_c_mapping_u_u.optional_pointer))
			return (FALSE);
		break;
	case PRES_C_MAPPING_IGNORE:
		break;
	case PRES_C_MAPPING_SYSTEM_EXCEPTION:
		break;
	case PRES_C_MAPPING_DIRECTION:
		if (!xdr_pres_c_mapping_direction(xdrs, &objp->pres_c_mapping_u_u.direction))
			return (FALSE);
		break;
	case PRES_C_MAPPING_SID:
		if (!xdr_pres_c_mapping_sid(xdrs, &objp->pres_c_mapping_u_u.sid))
			return (FALSE);
		break;
	case PRES_C_MAPPING_ARGUMENT:
		if (!xdr_pres_c_mapping_argument(xdrs, &objp->pres_c_mapping_u_u.argument))
			return (FALSE);
		break;
	case PRES_C_MAPPING_MESSAGE_ATTRIBUTE:
		if (!xdr_pres_c_mapping_message_attribute(xdrs, &objp->pres_c_mapping_u_u.message_attribute))
			return (FALSE);
		break;
	case PRES_C_MAPPING_INITIALIZE:
		if (!xdr_pres_c_mapping_initialize(xdrs, &objp->pres_c_mapping_u_u.initialize))
			return (FALSE);
		break;
	case PRES_C_MAPPING_ILLEGAL:
		break;
	case PRES_C_MAPPING_VAR_REFERENCE:
		if (!xdr_pres_c_mapping_var_reference(xdrs, &objp->pres_c_mapping_u_u.var_ref))
			return (FALSE);
		break;
	case PRES_C_MAPPING_PARAM_ROOT:
		if (!xdr_pres_c_mapping_param_root(xdrs, &objp->pres_c_mapping_u_u.param_root))
			return (FALSE);
		break;
	case PRES_C_MAPPING_ELSEWHERE:
		break;
	case PRES_C_MAPPING_SELECTOR:
		if (!xdr_pres_c_mapping_selector(xdrs, &objp->pres_c_mapping_u_u.selector))
			return (FALSE);
		break;
	case PRES_C_MAPPING_TEMPORARY:
		if (!xdr_pres_c_temporary(xdrs, &objp->pres_c_mapping_u_u.temp))
			return (FALSE);
		break;
	case PRES_C_MAPPING_SINGLETON:
		if (!xdr_pres_c_mapping_singleton(xdrs, &objp->pres_c_mapping_u_u.singleton))
			return (FALSE);
		break;
	default:
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_pres_c_marshal_stub(xdrs, objp)
	register XDR *xdrs;
	pres_c_marshal_stub *objp;
{

	if (!xdr_cast_ref(xdrs, &objp->c_func))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->i))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->target_i))
		return (FALSE);
	if (!xdr_pres_c_mapping(xdrs, &objp->seethru_map))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_stub_op_flags(xdrs, objp)
	register XDR *xdrs;
	pres_c_stub_op_flags *objp;
{

	if (!xdr_u_int(xdrs, objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_client_stub(xdrs, objp)
	register XDR *xdrs;
	pres_c_client_stub *objp;
{

	if (!xdr_cast_ref(xdrs, &objp->c_func))
		return (FALSE);
	if (!xdr_pres_c_stub_op_flags(xdrs, &objp->op_flags))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->request_itype))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->reply_itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->request_i))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->reply_i))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->target_itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->target_i))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->client_itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->client_i))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->error_itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->error_i))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_server_func(xdrs, objp)
	register XDR *xdrs;
	pres_c_server_func *objp;
{

	if (!xdr_cast_ref(xdrs, &objp->c_func))
		return (FALSE);
	if (!xdr_pres_c_stub_op_flags(xdrs, &objp->op_flags))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->request_i))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->reply_i))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->target_itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->target_i))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->client_itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->client_i))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->error_itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->error_i))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_receive_func(xdrs, objp)
	register XDR *xdrs;
	pres_c_receive_func *objp;
{

	if (!xdr_cast_ref(xdrs, &objp->c_func))
		return (FALSE);
	if (!xdr_pres_c_stub_op_flags(xdrs, &objp->op_flags))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->simple_msg_itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->msg_i))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->target_itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->target_i))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->client_itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->client_i))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->error_itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->error_i))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_func_kind(xdrs, objp)
	register XDR *xdrs;
	pres_c_func_kind *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_func(xdrs, objp)
	register XDR *xdrs;
	pres_c_func *objp;
{

	if (!xdr_pres_c_func_kind(xdrs, &objp->kind))
		return (FALSE);
	switch (objp->kind) {
	case PRES_C_SERVER_FUNC:
		if (!xdr_pres_c_server_func(xdrs, &objp->pres_c_func_u.sfunc))
			return (FALSE);
		break;
	case PRES_C_RECEIVE_FUNC:
		if (!xdr_pres_c_receive_func(xdrs, &objp->pres_c_func_u.rfunc))
			return (FALSE);
		break;
	default:
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_pres_c_skel(xdrs, objp)
	register XDR *xdrs;
	pres_c_skel *objp;
{

	if (!xdr_cast_ref(xdrs, &objp->c_def))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->request_itype))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->reply_itype))
		return (FALSE);
	if (!xdr_array(xdrs, (char **)&objp->funcs.funcs_val, (u_int *) &objp->funcs.funcs_len, ~0,
		sizeof (pres_c_func), (xdrproc_t) xdr_pres_c_func))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_msg_stub(xdrs, objp)
	register XDR *xdrs;
	pres_c_msg_stub *objp;
{

	if (!xdr_cast_ref(xdrs, &objp->c_func))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->msg_itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->msg_i))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->target_itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->target_i))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->request))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_msg_marshal_stub(xdrs, objp)
	register XDR *xdrs;
	pres_c_msg_marshal_stub *objp;
{

	if (!xdr_cast_ref(xdrs, &objp->c_func))
		return (FALSE);
	if (!xdr_pres_c_stub_op_flags(xdrs, &objp->op_flags))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->i))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->client))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->request))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->reply_handler_name, ~0))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_continue_stub(xdrs, objp)
	register XDR *xdrs;
	pres_c_continue_stub *objp;
{

	if (!xdr_cast_ref(xdrs, &objp->c_func))
		return (FALSE);
	if (!xdr_mint_ref(xdrs, &objp->itype))
		return (FALSE);
	if (!xdr_pres_c_inline(xdrs, &objp->i))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->request))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_stub_kind(xdrs, objp)
	register XDR *xdrs;
	pres_c_stub_kind *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_stub(xdrs, objp)
	register XDR *xdrs;
	pres_c_stub *objp;
{

	if (!xdr_pres_c_stub_kind(xdrs, &objp->kind))
		return (FALSE);
	switch (objp->kind) {
	case PRES_C_MARSHAL_STUB:
		if (!xdr_pres_c_marshal_stub(xdrs, &objp->pres_c_stub_u.mstub))
			return (FALSE);
		break;
	case PRES_C_UNMARSHAL_STUB:
		if (!xdr_pres_c_marshal_stub(xdrs, &objp->pres_c_stub_u.ustub))
			return (FALSE);
		break;
	case PRES_C_CLIENT_STUB:
		if (!xdr_pres_c_client_stub(xdrs, &objp->pres_c_stub_u.cstub))
			return (FALSE);
		break;
	case PRES_C_CLIENT_SKEL:
		if (!xdr_pres_c_skel(xdrs, &objp->pres_c_stub_u.cskel))
			return (FALSE);
		break;
	case PRES_C_SERVER_SKEL:
		if (!xdr_pres_c_skel(xdrs, &objp->pres_c_stub_u.sskel))
			return (FALSE);
		break;
	case PRES_C_SEND_STUB:
		if (!xdr_pres_c_msg_stub(xdrs, &objp->pres_c_stub_u.send_stub))
			return (FALSE);
		break;
	case PRES_C_RECV_STUB:
		if (!xdr_pres_c_msg_stub(xdrs, &objp->pres_c_stub_u.recv_stub))
			return (FALSE);
		break;
	case PRES_C_MESSAGE_MARSHAL_STUB:
		if (!xdr_pres_c_msg_marshal_stub(xdrs, &objp->pres_c_stub_u.mmstub))
			return (FALSE);
		break;
	case PRES_C_MESSAGE_UNMARSHAL_STUB:
		if (!xdr_pres_c_msg_marshal_stub(xdrs, &objp->pres_c_stub_u.mustub))
			return (FALSE);
		break;
	case PRES_C_CONTINUE_STUB:
		if (!xdr_pres_c_continue_stub(xdrs, &objp->pres_c_stub_u.continue_stub))
			return (FALSE);
		break;
	default:
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_tag_data_kind(xdrs, objp)
	register XDR *xdrs;
	tag_data_kind *objp;
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_tag_list_ptr(xdrs, objp)
	register XDR *xdrs;
	tag_list_ptr *objp;
{

	if (!xdr_pointer(xdrs, (char **)objp, sizeof (struct tag_list), (xdrproc_t) xdr_tag_list))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_tag_string_array(xdrs, objp)
	register XDR *xdrs;
	tag_string_array *objp;
{

	if (!xdr_string(xdrs, objp, ~0))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_tag_object_array(xdrs, objp)
	register XDR *xdrs;
	tag_object_array *objp;
{

	if (!xdr_array(xdrs, (char **)&objp->tag_object_array_val, (u_int *) &objp->tag_object_array_len, ~0,
		sizeof (char), (xdrproc_t) xdr_char))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_tag_data(xdrs, objp)
	register XDR *xdrs;
	tag_data *objp;
{

	if (!xdr_tag_data_kind(xdrs, &objp->kind))
		return (FALSE);
	switch (objp->kind) {
	case TAG_NONE:
		break;
	case TAG_ANY:
		break;
	case TAG_TAG_LIST:
		if (!xdr_tag_list_ptr(xdrs, &objp->tag_data_u.tl))
			return (FALSE);
		break;
	case TAG_BOOL:
		if (!xdr_char(xdrs, &objp->tag_data_u.b))
			return (FALSE);
		break;
	case TAG_STRING:
		if (!xdr_string(xdrs, &objp->tag_data_u.str, ~0))
			return (FALSE);
		break;
	case TAG_INTEGER:
		if (!xdr_int(xdrs, &objp->tag_data_u.i))
			return (FALSE);
		break;
	case TAG_FLOAT:
		if (!xdr_float(xdrs, &objp->tag_data_u.f))
			return (FALSE);
		break;
	case TAG_REF:
		if (!xdr_string(xdrs, &objp->tag_data_u.ref, ~0))
			return (FALSE);
		break;
	case TAG_OBJECT:
		if (!xdr_tag_object_array(xdrs, &objp->tag_data_u.obj))
			return (FALSE);
		break;
	case TAG_CAST_SCOPED_NAME:
		if (!xdr_cast_scoped_name(xdrs, &objp->tag_data_u.scname))
			return (FALSE);
		break;
	case TAG_CAST_DEF:
		if (!xdr_cast_def_t(xdrs, &objp->tag_data_u.cdef))
			return (FALSE);
		break;
	case TAG_CAST_TYPE:
		if (!xdr_cast_type(xdrs, &objp->tag_data_u.ctype))
			return (FALSE);
		break;
	case TAG_CAST_EXPR:
		if (!xdr_cast_expr(xdrs, &objp->tag_data_u.cexpr))
			return (FALSE);
		break;
	case TAG_CAST_STMT:
		if (!xdr_cast_stmt(xdrs, &objp->tag_data_u.cstmt))
			return (FALSE);
		break;
	case TAG_CAST_INIT:
		if (!xdr_cast_init(xdrs, &objp->tag_data_u.cinit))
			return (FALSE);
		break;
	case TAG_TAG_LIST_ARRAY:
		if (!xdr_array(xdrs, (char **)&objp->tag_data_u.tl_a.tl_a_val, (u_int *) &objp->tag_data_u.tl_a.tl_a_len, ~0,
			sizeof (tag_list_ptr), (xdrproc_t) xdr_tag_list_ptr))
			return (FALSE);
		break;
	case TAG_BOOL_ARRAY:
		if (!xdr_array(xdrs, (char **)&objp->tag_data_u.b_a.b_a_val, (u_int *) &objp->tag_data_u.b_a.b_a_len, ~0,
			sizeof (char), (xdrproc_t) xdr_char))
			return (FALSE);
		break;
	case TAG_STRING_ARRAY:
		if (!xdr_array(xdrs, (char **)&objp->tag_data_u.str_a.str_a_val, (u_int *) &objp->tag_data_u.str_a.str_a_len, ~0,
			sizeof (tag_string_array), (xdrproc_t) xdr_tag_string_array))
			return (FALSE);
		break;
	case TAG_INTEGER_ARRAY:
		if (!xdr_array(xdrs, (char **)&objp->tag_data_u.i_a.i_a_val, (u_int *) &objp->tag_data_u.i_a.i_a_len, ~0,
			sizeof (int), (xdrproc_t) xdr_int))
			return (FALSE);
		break;
	case TAG_FLOAT_ARRAY:
		if (!xdr_array(xdrs, (char **)&objp->tag_data_u.f_a.f_a_val, (u_int *) &objp->tag_data_u.f_a.f_a_len, ~0,
			sizeof (float), (xdrproc_t) xdr_float))
			return (FALSE);
		break;
	case TAG_REF_ARRAY:
		if (!xdr_array(xdrs, (char **)&objp->tag_data_u.ref_a.ref_a_val, (u_int *) &objp->tag_data_u.ref_a.ref_a_len, ~0,
			sizeof (tag_string_array), (xdrproc_t) xdr_tag_string_array))
			return (FALSE);
		break;
	case TAG_OBJECT_ARRAY:
		if (!xdr_array(xdrs, (char **)&objp->tag_data_u.obj_a.obj_a_val, (u_int *) &objp->tag_data_u.obj_a.obj_a_len, ~0,
			sizeof (tag_object_array), (xdrproc_t) xdr_tag_object_array))
			return (FALSE);
		break;
	case TAG_CAST_SCOPED_NAME_ARRAY:
		if (!xdr_array(xdrs, (char **)&objp->tag_data_u.scname_a.scname_a_val, (u_int *) &objp->tag_data_u.scname_a.scname_a_len, ~0,
			sizeof (cast_scoped_name), (xdrproc_t) xdr_cast_scoped_name))
			return (FALSE);
		break;
	case TAG_CAST_DEF_ARRAY:
		if (!xdr_array(xdrs, (char **)&objp->tag_data_u.cdef_a.cdef_a_val, (u_int *) &objp->tag_data_u.cdef_a.cdef_a_len, ~0,
			sizeof (cast_def_t), (xdrproc_t) xdr_cast_def_t))
			return (FALSE);
		break;
	case TAG_CAST_TYPE_ARRAY:
		if (!xdr_array(xdrs, (char **)&objp->tag_data_u.ctype_a.ctype_a_val, (u_int *) &objp->tag_data_u.ctype_a.ctype_a_len, ~0,
			sizeof (cast_type), (xdrproc_t) xdr_cast_type))
			return (FALSE);
		break;
	case TAG_CAST_EXPR_ARRAY:
		if (!xdr_array(xdrs, (char **)&objp->tag_data_u.cexpr_a.cexpr_a_val, (u_int *) &objp->tag_data_u.cexpr_a.cexpr_a_len, ~0,
			sizeof (cast_expr), (xdrproc_t) xdr_cast_expr))
			return (FALSE);
		break;
	case TAG_CAST_STMT_ARRAY:
		if (!xdr_array(xdrs, (char **)&objp->tag_data_u.cstmt_a.cstmt_a_val, (u_int *) &objp->tag_data_u.cstmt_a.cstmt_a_len, ~0,
			sizeof (cast_stmt), (xdrproc_t) xdr_cast_stmt))
			return (FALSE);
		break;
	case TAG_CAST_INIT_ARRAY:
		if (!xdr_array(xdrs, (char **)&objp->tag_data_u.cinit_a.cinit_a_val, (u_int *) &objp->tag_data_u.cinit_a.cinit_a_len, ~0,
			sizeof (cast_init), (xdrproc_t) xdr_cast_init))
			return (FALSE);
		break;
	default:
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_tag_item(xdrs, objp)
	register XDR *xdrs;
	tag_item *objp;
{

	if (!xdr_string(xdrs, &objp->tag, ~0))
		return (FALSE);
	if (!xdr_tag_data(xdrs, &objp->data))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_tag_list(xdrs, objp)
	register XDR *xdrs;
	tag_list *objp;
{

	if (!xdr_pointer(xdrs, (char **)&objp->parent, sizeof (tag_list), (xdrproc_t) xdr_tag_list))
		return (FALSE);
	if (!xdr_array(xdrs, (char **)&objp->items.items_val, (u_int *) &objp->items.items_len, ~0,
		sizeof (tag_item), (xdrproc_t) xdr_tag_item))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_pres_c_1(xdrs, objp)
	register XDR *xdrs;
	pres_c_1 *objp;
{

	if (!xdr_mint_1(xdrs, &objp->mint))
		return (FALSE);
	if (!xdr_cast_1(xdrs, &objp->cast))
		return (FALSE);
	if (!xdr_cast_1(xdrs, &objp->stubs_cast))
		return (FALSE);
	if (!xdr_cast_1(xdrs, &objp->pres_cast))
		return (FALSE);
	if (!xdr_aoi(xdrs, &objp->a))
		return (FALSE);
	if (!xdr_array(xdrs, (char **)&objp->stubs.stubs_val, (u_int *) &objp->stubs.stubs_len, ~0,
		sizeof (pres_c_stub), (xdrproc_t) xdr_pres_c_stub))
		return (FALSE);
	if (!xdr_string(xdrs, &objp->pres_context, ~0))
		return (FALSE);
	if (!xdr_array(xdrs, (char **)&objp->error_mappings.error_mappings_val, (u_int *) &objp->error_mappings.error_mappings_len, ~0,
		sizeof (cast_expr), (xdrproc_t) xdr_cast_expr))
		return (FALSE);
	if (!xdr_array(xdrs, (char **)&objp->unpresented_channels.unpresented_channels_val, (u_int *) &objp->unpresented_channels.unpresented_channels_len, ~0,
		sizeof (data_channel_mask), (xdrproc_t) xdr_data_channel_mask))
		return (FALSE);
	if (!xdr_pointer(xdrs, (char **)&objp->pres_attrs, sizeof (tag_list), (xdrproc_t) xdr_tag_list))
		return (FALSE);
	if (!xdr_meta(xdrs, &objp->meta_data))
		return (FALSE);
	if (!xdr_int(xdrs, &objp->cast_language))
		return (FALSE);
	return (TRUE);
}
