#include "expr.h"
#include "stmt.h"
#include "decl.h"
#include "type.h"
#include "symbol.h"
#include "special.h"
#include "scope.h"
#include "param_list.h"

struct decl *decl_create(char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next)
{
    struct decl *d = special_xmalloc(sizeof(*d));
    d->name = name;
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;
    return d;
}

void decl_print(struct decl *d, int tab)
{
    if (d)
    {
        printf("%s", d->name);
        printf(":");
        type_print(d->type, tab);
        if (d->value)
        {
            printf(" = ");
        }
        expr_print(d->value, tab);
        if (d->type->kind == TYPE_FUNCTION && d->code)
        {
            printf(" = ");
        }
        stmt_print(d->code, tab);
        if (d->value || !d->code)
        {
            printf(";");
        }
        printf("\n");
        special_tabprinter(tab);
        decl_print(d->next, tab);
    }
}

void decl_resolve(struct decl *d)
{
    if (!d)
        return;
    d->symbol = symbol_create(scope_level() ? SYMBOL_LOCAL : SYMBOL_GLOBAL, d->type, d->name, 0);

    expr_resolve(d->value);
    scope_bind(d->name, d->symbol);

    if (d->code)
    {
        scope_enter();
        param_list_resolve(d->type->params);
        stmt_resolve(d->code);
        scope_exit();
    }
    decl_resolve(d->next);
}

void decl_typecheck(struct decl *d)
{
    if (d->value)
    {
        struct type *t = expr_typecheck(d->value);
        if (!type_compare(t, d->symbol->type))
        {
            // print error
        }
    }
    if (d->code)
    {
        stmt_typecheck(d->code);
    }
}
