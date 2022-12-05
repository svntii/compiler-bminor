#include "decl.h"
#include "stmt.h"
#include "symbol.h"
#include "scope.h"
#include "type.h"
#include "expr.h"
#include "param_list.h"
#include "special.h"
extern int MAIN_RESOLVEERROR_COUNT;
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
    // created a symbol for d

    d->symbol = symbol_create(scope_level() > 1 ? SYMBOL_LOCAL : SYMBOL_GLOBAL, d->type, d->name, 0, 0);

    if (d->type->kind == TYPE_FUNCTION && !d->code)
    {
        d->symbol->prototype = 1;
    }

    // x:integer; or y:integer = 10;
    struct symbol *s = scope_lookup_current(d->name);

    if (s && !type_compare(s->type, d->type) && s->prototype)
    {
        // check if it is a prototype and the types match
        MAIN_RESOLVEERROR_COUNT++;
        printf("resolve error: the defintion of %s does not match its prototype, please double check the types\n", s->name);
    }

    expr_resolve(d->value);
    scope_bind(d->name, d->symbol);

    // main: function void = { ... }

    if (d->code)
    {
        symbol_local_count_reset();
        scope_enter();
        param_list_resolve(d->type->params);
        stmt_resolve(d->code);
        scope_exit();
    }
    // GOTO next decl
    decl_resolve(d->next);
    return;
}

void decl_typecheck(struct decl *d)
{
    /*char *name;           test2
    struct type *type;      function boolean
    struct expr *value;     0
    struct stmt *code;      0
    struct symbol *symbol;
    struct decl *next;


    */

    if (!d)
        return;

    if (d->value)
    {
        struct type *t = expr_typecheck(d->value);
        if (d->symbol->type->kind == TYPE_AUTO)
        {
            d->symbol->type = type_copy(t);
            d->type = d->symbol->type;
        }
        if (d->symbol->type->kind == TYPE_ARRAY)
        {
            /* code typechecking arrays */
            if (!type_compare(t, d->symbol->type->subtype))
            {
                special_decl_error_handler(d, t);
            }

            struct type *inside_array_type = expr_typecheck(d->type->inside_array);
            if (inside_array_type->kind != TYPE_INTEGER)
            {
                special_decl_error_handler(d, inside_array_type);
            }
        }
        else if (!type_compare(t, d->symbol->type))
        {
            special_decl_error_handler(d, t);
        }
    }

    if (d->code)
    {
        if (!param_list_compare(d->symbol->type->params, d->type->params))
        {
            special_decl_error_handler(d, d->symbol->type);
        }
        stmt_typecheck(d->code, d->symbol);
    }
    else if (d->type->kind == TYPE_FUNCTION)
    {
    }
    decl_typecheck(d->next);
}
