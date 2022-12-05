typedef enum
{
    SYMBOL_LOCAL,
    SYMBOL_PARAM,
    SYMBOL_GLOBAL
} symbol_t;

struct symbol
{
    symbol_t kind;
    struct type *type;
    char *name;
    int which;
    int prototype;
};

void symbol_local_count_reset(void);

struct symbol *symbol_create(symbol_t kind, struct type *type, char *name, int which, int prototype);
void symbol_print(struct symbol *s);
const char *symbol_codegen(struct symbol *s); // returns a string which is a fragment of an instruction, representing the address computation needed for a given symbol