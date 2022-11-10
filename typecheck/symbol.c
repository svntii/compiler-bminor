#include "special.h"
#include "symbol.h"
#include "type.h"

struct symbol *symbol_create(symbol_t kind, struct type *type, char *name, int which)
{
    struct symbol *s = special_xmalloc(sizeof(struct symbol));
    s->kind = kind;
    s->type = type;
    s->name = name;
    s->which = which;
    return s;
}
