#include "type.h"
#include "param_list.h"
#include "special.h"

struct param_list *param_list_create(char *name, struct type *type, struct symbol *symbol, struct param_list *next)
{
    struct param_list *p = xmalloc(sizeof(struct param_list));
    p->name = name;
    p->type = type;
    p->symbol = symbol;
    p->next = next;
    return p;
}