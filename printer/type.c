#include "type.h"
#include "param_list.h"
#include "special.h"

struct type *type_create(type_t kind, struct type *subtype, struct param_list *params)
{
    struct type *t = xmalloc(sizeof(struct type));
    t->kind = kind;
    t->subtype = subtype;
    t->params = params;
    return t;
}