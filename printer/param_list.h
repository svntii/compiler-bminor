

struct param_list
{
    char *name;
    struct type *type;
    struct symbol *symbol;
    struct param_list *next;
};

struct param_list *param_list_create(char *name, struct type *type, struct symbol *symbol, struct param_list *next);
void param_print(struct param_list *p, int tab);
