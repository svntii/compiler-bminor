#include "expr.h"
#include "stmt.h"
#include "decl.h"
#include "type.h"

#include "special.h"

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
        if (d->type->kind == TYPE_FUNCTION)
        {
            printf(" = ");
        }
        stmt_print(d->code, tab);
        if (d->value || !d->code)
        {
            printf(";");
        }
        printf("\n");
        decl_print(d->next, tab);
    }
}