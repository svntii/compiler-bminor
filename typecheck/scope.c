#include "special.h"
#include "scope.h"
#include "hash_table.h"
#include "symbol.h"

struct scope_stack *HEAD;
int LEVEL = 0;

struct scope_stack *scope_create(struct hash_table *h)
{
    struct scope_stack *s = special_xmalloc(sizeof(struct scope_stack));
    s->curr = h;
    return s;
}

void scope_enter()
{
    struct scope_stack *s = scope_create(hash_table_create(0, 0));
    s->prev = HEAD;
    HEAD = s;
    LEVEL++;
}
void scope_exit()
{
    struct scope_stack *delete = HEAD;
    HEAD = HEAD->prev;
    hash_table_delete(delete->curr);
    free(delete);
}
int scope_level()
{
    return LEVEL;
}

void scope_bind(const char *name, void *s)
{
    hash_table_insert(HEAD->curr, name, s);
}

struct symbol *scope_lookup(const char *name)
{
    struct scope_stack *lookup = HEAD;
    while (lookup)
    {
        struct symbol *s = hash_table_lookup(lookup->curr, name);
        if (s)
        {
            return s;
        }
        lookup = lookup->prev;
    }
    return 0;
}
struct symbol *scope_lookup_current(const char *name)
{
    return hash_table_lookup(HEAD->curr, name);
}