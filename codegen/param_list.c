#include "param_list.h"
#include "type.h"
#include "scope.h"
#include "decl.h"
#include "stmt.h"
#include "symbol.h"
#include "special.h"
extern int MAIN_RESOLVEERROR_COUNT;
struct param_list *param_list_create(char *name, struct type *type, struct symbol *symbol, struct param_list *next)
{
    struct param_list *p = special_xmalloc(sizeof(struct param_list));
    p->name = name;
    p->type = type;
    p->symbol = symbol;
    p->next = next;
    return p;
}

void param_list_print(struct param_list *p, int tab)
{
    if (p)
    {
        printf("%s", p->name);
        printf(":");
        type_print(p->type, tab);
        if (p->next)
            printf(", ");
        param_list_print(p->next, tab);
    }
}
struct param_list *param_list_copy(struct param_list *param)
{
    if (!param)
        return 0;
    struct param_list *p = param_list_create(param->name, type_copy(param->type), param->symbol, param_list_copy(param->next));
    return p;
}

int param_list_compare(struct param_list *a, struct param_list *b)
{
    if (!a && !b)
        return 1;
    if (!a || !b)
        return 0;

    if (type_compare(a->type, b->type))
    {
        return param_list_compare(a->next, b->next);
    }

    return 0;
}

void param_list_resolve(struct param_list *p)
{
    if (!p)
        return;
    p->symbol = symbol_create(scope_level() ? SYMBOL_LOCAL : SYMBOL_GLOBAL, p->type, p->name, 0, 0);

    struct symbol *s = scope_lookup_current(p->name);

    if (s)
    {
        MAIN_RESOLVEERROR_COUNT++;
        printf("resolve error: %s is already defined (param)\n", p->name);
    }
    else
    {
        printf("%s resolves to (param)\n", p->name);
    }

    scope_bind(p->name, p->symbol);

    param_list_resolve(p->next);
}

void param_list_delete(struct param_list *p)
{
    if (!p)
        return;
    type_delete(p->type);
    param_list_delete(p->next);
    free(p);
    return;
}
