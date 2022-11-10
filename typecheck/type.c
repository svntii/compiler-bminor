#include "type.h"
#include "param_list.h"
#include "special.h"

struct type *type_create(type_t kind, struct type *subtype, struct param_list *params, struct expr *inside_array, int return_type)
{
    struct type *t = special_xmalloc(sizeof(struct type));
    t->kind = kind;
    t->subtype = subtype;
    t->params = params;
    t->inside_array = inside_array;
    return t;
}

void type_print(struct type *t, int tab)
{

    if (!t)
        return;

    switch (t->kind)
    {
    case TYPE_BOOLEAN:
        printf(" boolean");
        break;
    case TYPE_CHAR:
        printf(" char");
        break;
    case TYPE_INTEGER:
        printf(" integer");
        break;
    case TYPE_STRING:
        printf(" string");
        break;
    case TYPE_ARRAY:
        printf(" array");
        printf("[");
        printf("]");
        type_print(t->subtype, tab);
        break;
    case TYPE_FUNCTION:
        printf(" function");
        type_print(t->subtype, tab);
        if (t->subtype->kind != TYPE_FUNCTION && t->return_type == 0)
        {
            printf("(");
        }
        param_list_print(t->params, tab);
        if (t->subtype->kind != TYPE_FUNCTION && t->return_type == 0)
        {
            printf(") ");
        }
        break;
    case TYPE_AUTO:
        printf(" auto");
        type_print(t->subtype, tab);
        break;
    case TYPE_VOID:
        printf(" void");
        break;
    default:
        break;
    }

    return;
}

struct type *type_copy(struct type *t)
{

    if (!t)
        return 0;
    struct type *new_t = type_create(t->kind, type_copy(t->subtype), param_list_copy(t->params), t->inside_array, t->return_type);
    return new_t;
}

void type_delete(struct type *t)
{
    if (!t)
        return;
    type_delete(t->subtype);
    param_list_delete(t->params);

    free(t);
    return;
}

int type_compare(struct type *a, struct type *b)
{
    if (!a && !b) // both null
        return 1;
    
    if (!a || !b) // one is null 
        return 0;
    
    if (a->kind == b->kind)
    {
        if (a->kind == TYPE_BOOLEAN || a->kind == TYPE_CHAR || a->kind == TYPE_INTEGER || a->kind == TYPE_STRING)
        {
            return 1;
        }
        else if (a->kind == TYPE_ARRAY)
        {
            return type_compare(a->subtype, b->subtype);
        }
        else if (a->kind == TYPE_FUNCTION)
        {
            return type_compare(a->subtype, b->subtype) && param_list_compare(a->params, b->params);
        }
        else
        {
            return 0;
        }
    }
}