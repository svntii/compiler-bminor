
struct scope_stack
{
    struct hash_table *curr;
    struct scope_stack *prev;
};

struct scope_stack *scope_create(struct hash_table *h);
void scope_enter();
void scope_exit();
int scope_level();
void scope_bind(const char *name, void *s); // connect name with symbol
struct symbol *scope_lookup(const char *name);
struct symbol *scope_lookup_current(const char *name);
