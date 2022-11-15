#include "symbol.h"
#include "decl.h"
#include "expr.h"
#include "stmt.h"
#include "scope.h"
#include "special.h"

struct symbol *symbol_create(symbol_t kind, struct type *type, char *name, int which, int prototype)
{
    struct symbol *s = special_xmalloc(sizeof(struct symbol));
    s->kind = kind;
    s->type = type;
    s->name = name;
    s->which = which;
    s->prototype = prototype;
    return s;
}
void symbol_print(struct symbol *s)
{
    switch (s->kind)
    {
    case SYMBOL_GLOBAL:
        /* code */
        printf("(global) %s\n", s->name);
        break;
    case SYMBOL_LOCAL:
        printf("(L%d) %s\n", scope_level(), s->name);
        break;
    case SYMBOL_PARAM:
        printf("(PARAM) %s\n", s->name);
        break;
    default:
        break;
    }
}
