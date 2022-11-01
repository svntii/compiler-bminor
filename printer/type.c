#include "type.h"
#include "param_list.h"
#include "special.h"

struct type *type_create(type_t kind, struct type *subtype, struct param_list *params, struct expr *inside_array)
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
        printf(" boolean ");
        break;
    case TYPE_CHAR:
        printf(" char ");
        break;
    case TYPE_INTEGER:
        printf(" integer ");
        break;
    case TYPE_STRING:
        printf(" string ");
        break;
    case TYPE_ARRAY:
        printf(" array ");
        printf("[");
        printf("]");
        type_print(t->subtype, tab);
        break;
    case TYPE_FUNCTION:
        printf(" function");
        type_print(t->subtype, tab);
        if (t->subtype->kind != TYPE_FUNCTION)
        {
            printf("(");
        }
        param_print(t->params, tab);
        if (t->subtype->kind != TYPE_FUNCTION)
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
