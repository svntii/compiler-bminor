#include "expr.h"
#include "special.h"

struct expr *expr_create(expr_t kind, struct expr *left, struct expr *right)
{
    struct expr *e = special_xmalloc(sizeof(struct expr)); // we have declared a pointer called e and allocated appropriate memory to that pointer
    e->kind = kind;
    e->left = left;
    e->right = right;
    return e;
}

struct expr *expr_create_name(const char *name)
{
    struct expr *e = expr_create(EXPR_NAME, 0, 0);
    e->name = name;
    return e;
}

struct expr *expr_create_integer_literal(int i)
{
    struct expr *e = expr_create(EXPR_INTEGER_LITERAL, 0, 0);
    e->literal_value = i;
    return e;
}

struct expr *expr_create_boolean_literal(int b)
{
    struct expr *e = expr_create(EXPR_BOOLEAN_LITERAL, 0, 0);
    e->literal_value = b;
    return e;
}

struct expr *expr_create_char_literal(char c)
{
    struct expr *e = expr_create(EXPR_CHAR_LITERAL, 0, 0);
    e->literal_value = c; // look again
    return e;
}

struct expr *expr_create_string_literal(const char *str)
{
    struct expr *e = expr_create(EXPR_STRING_LITERAL, 0, 0);
    e->string_literal = str;
    return e;
}

void expr_print(struct expr *e, int tab)
{
    if (!e)
        return;

    switch (e->kind)
    {
    case EXPR_ADD:
        expr_print(e->left, tab);
        printf(" + ");
        expr_print(e->right, tab);
        break;
    case EXPR_SUB:
        expr_print(e->left, tab);
        printf(" - ");
        expr_print(e->right, tab);
        break;
    case EXPR_MULT:
        expr_print(e->left, tab);
        printf(" * ");
        expr_print(e->right, tab);
        break;
    case EXPR_DIV:
        expr_print(e->left, tab);
        printf(" / ");
        expr_print(e->right, tab);
        break;
    case EXPR_OR:
        expr_print(e->left, tab);
        printf(" || ");
        expr_print(e->right, tab);
        break;
    case EXPR_AND:
        expr_print(e->left, tab);
        printf(" && ");
        expr_print(e->right, tab);
        break;
    case EXPR_LT:
        expr_print(e->left, tab);
        printf(" < ");
        expr_print(e->right, tab);
        break;
    case EXPR_LTE:
        expr_print(e->left, tab);
        printf(" <= ");
        expr_print(e->right, tab);
        break;
    case EXPR_GT:
        expr_print(e->left, tab);
        printf(" > ");
        expr_print(e->right, tab);
        break;
    case EXPR_GTE:
        expr_print(e->left, tab);
        printf(" >= ");
        expr_print(e->right, tab);
        break;
    case EXPR_EQ:
        expr_print(e->left, tab);
        printf(" == ");
        expr_print(e->right, tab);
        break;
    case EXPR_NEQ:
        expr_print(e->left, tab);
        printf(" != ");
        expr_print(e->right, tab);
        break;
    case EXPR_MOD:
        expr_print(e->left, tab);
        printf(" %% ");
        expr_print(e->right, tab);
        break;
    case EXPR_EXP:
        expr_print(e->left, tab);
        printf(" ^ ");
        expr_print(e->right, tab);
        break;
    case EXPR_NEGATE:
        printf("-");
        expr_print(e->left, tab);
        break;
    case EXPR_NOT:
        printf("!");
        expr_print(e->left, tab);
        break;
    case EXPR_POSIN:
        expr_print(e->right, tab);
        printf("++");
        break;
    case EXPR_POSDEC:
        expr_print(e->right, tab);
        printf("--");
        break;
    case EXPR_GROUP:
        printf("( ");
        expr_print(e->left, tab);
        printf(" )");
        break;
    case EXPR_SUBSCRIPT:
        expr_print(e->left, tab);
        printf("[ ");
        expr_print(e->right, tab);
        printf(" ]");
        break;
    case EXPR_FUNCTION_CALL:
        expr_print(e->left, tab);
        printf("( ");
        expr_print(e->right, tab);
        printf(" )");
        break;
    case EXPR_ASSIGNMENT:
        expr_print(e->left, tab);
        printf(" = ");
        expr_print(e->right, tab);
        break;
    case EXPR_TERN:
        printf(" ? ");
        expr_print(e->left, tab);
        printf(" : ");
        expr_print(e->right, tab);
        break;
    case EXPR_INTEGER_LITERAL:
        printf("%d", e->literal_value);
        break;
    case EXPR_BOOLEAN_LITERAL:
        if (e->literal_value)
        {
            printf("true");
        }
        else
        {
            printf("false");
        }
        break;
    case EXPR_CHAR_LITERAL:
        printf("'");
        printf("%c", e->literal_value);
        printf("'");
        break;
    case EXPR_STRING_LITERAL:
        printf("%s", e->string_literal);
        break;

    case EXPR_ARRAY_LITERAL:
        printf("{ ");
        expr_print(e->left, tab);
        printf(" , ");
        expr_print(e->right, tab);
        printf(" }");
        break;
    case EXPR_NAME:
        printf("%s", e->name);
        break;
    default:
        break;
    }
}