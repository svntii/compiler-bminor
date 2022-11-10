#include "special.h"
#include "expr.h"
#include "type.h"

void *special_xmalloc(size_t size)
{
    void *p = (void *)malloc(size);
    if (!p)
        abort();
    return p;
}
void special_tabprinter(int tab)
{
    for (int i = 0; i < tab; i++)
    {
        printf("    ");
    }
}

void special_error_handler(struct expr *e, struct type *lt, struct type *rt)
{
    /*

    EXPR_NEGATE,
    EXPR_NOT,
    EXPR_POSIN,
    EXPR_POSDEC,
    EXPR_GROUP,
    EXPR_SUBSCRIPT,
    EXPR_SUBSCRIPT_SUB,
    EXPR_FUNCTION_CALL,
    EXPR_ARG,
    EXPR_ASSIGNMENT,
    EXPR_TERN,
    EXPR_ARRAY_LITERAL,
    EXPR_NAME*/
    // error: cannot compare a boolean (b) to an integer (5)
    printf("error: Dearest programmer, you cannot");

    switch (e->kind)
    {
    case EXPR_ADD:
        printf("add a ");
        type_print(lt, 0);
        printf(" (");
        expr_print(e->left, 0);
        printf(" ) to a ");
        type_print(rt, 0);
        printf(" (");
        expr_print(e->right, 0);
        printf(" )\n");
    case EXPR_SUB:
        printf("sub a ");
        type_print(lt, 0);
        printf(" (");
        expr_print(e->left, 0);
        printf(" ) to a ");
        type_print(rt, 0);
        printf(" (");
        expr_print(e->right, 0);
        printf(" )\n");
    case EXPR_MULT:
        printf("multiply a ");
        type_print(lt, 0);
        printf(" (");
        expr_print(e->left, 0);
        printf(" ) to a ");
        type_print(rt, 0);
        printf(" (");
        expr_print(e->right, 0);
        printf(" )\n");
    case EXPR_DIV:
        printf("divide a ");
        type_print(lt, 0);
        printf(" (");
        expr_print(e->left, 0);
        printf(" ) to a ");
        type_print(rt, 0);
        printf(" (");
        expr_print(e->right, 0);
        printf(" )\n");
    case EXPR_EXP:
        printf("exponentiate a ");
        type_print(lt, 0);
        printf(" (");
        expr_print(e->left, 0);
        printf(" ) to a ");
        type_print(rt, 0);
        printf(" (");
        expr_print(e->right, 0);
        printf(" )\n");
    case EXPR_MOD:
        printf("modulo a ");
        type_print(lt, 0);
        printf(" (");
        expr_print(e->left, 0);
        printf(" ) to a ");
        type_print(rt, 0);
        printf(" (");
        expr_print(e->right, 0);
        printf(" )\n");
    case EXPR_AND:
        printf(" && a ");
        type_print(lt, 0);
        printf(" (");
        expr_print(e->left, 0);
        printf(" ) to a ");
        type_print(rt, 0);
        printf(" (");
        expr_print(e->right, 0);
        printf(" )\n");
    case EXPR_OR:
        printf(" || a ");
        type_print(lt, 0);
        printf(" (");
        expr_print(e->left, 0);
        printf(" ) to a ");
        type_print(rt, 0);
        printf(" (");
        expr_print(e->right, 0);
        printf(" )\n");
    case EXPR_LT:
    case EXPR_LTE:
    case EXPR_GT:
    case EXPR_GTE:
    case EXPR_EQ:
    case EXPR_NEQ:
        printf(" compare a ");
        type_print(lt, 0);
        printf(" (");
        expr_print(e->left, 0);
        printf(" ) to a ");
        type_print(rt, 0);
        printf(" (");
        expr_print(e->right, 0);
        printf(" )\n");

        break;
    default:
        break;
    }
}