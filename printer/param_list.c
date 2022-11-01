#include "type.h"
#include "param_list.h"
#include "special.h"
#include <stdio.h>

struct param_list *param_list_create(char *name, struct type *type, struct symbol *symbol, struct param_list *next)
{
    struct param_list *p = special_xmalloc(sizeof(struct param_list));
    p->name = name;
    p->type = type;
    p->symbol = symbol;
    p->next = next;
    return p;
}

void param_print(struct param_list *p, int tab)
{
    if (p)
    {
        printf("%s", p->name);
        printf(":");
        type_print(p->type, tab);
        if (p->next)
            printf(", ");
        param_print(p->next, tab);
    }
}