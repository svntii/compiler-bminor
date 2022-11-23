#include "expr.h"
#include "stmt.h"
#include "type.h"
#include "hash_table.h"
#include "scope.h"
#include "decl.h"
#include "special.h"
extern int MAIN_TYPEERROR_COUNT;

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

void special_expr_error_handler(struct expr *e, struct type *lt, struct type *rt)
{
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
    case EXPR_NEGATE:
        printf(" negate a ");
        type_print(rt, 0);
        printf(" (");
        expr_print(e->right, 0);
        printf(" )\n");
        break;
    case EXPR_NOT:
        printf(" negate a ");
        type_print(rt, 0);
        printf(" (");
        expr_print(e->right, 0);
        printf(" )\n");
        break;
    case EXPR_POSIN:
        printf(" increment a ");
        type_print(lt, 0);
        printf(" (");
        expr_print(e->left, 0);
        printf(" )\n");
        break;
    case EXPR_POSDEC:
        printf(" decrement a ");
        type_print(lt, 0);
        printf(" (");
        expr_print(e->left, 0);
        printf(" )\n");
        break;
    case EXPR_SUBSCRIPT:
    case EXPR_SUBSCRIPT_SUB:
        printf(" subscript  ");
        type_print(lt, 0);
        printf(" (");
        expr_print(e->left, 0);
        printf(" )  ");
        type_print(rt, 0);
        printf(" (");
        expr_print(e->right, 0);
        printf(" )\n");

        break;
    case EXPR_TERN:
        printf(" evaluate a  ");
        type_print(lt, 0);
        printf(" (");
        expr_print(e->left, 0);
        printf(" )  in ternary operator ");
        type_print(rt, 0);
        printf(" (");
        expr_print(e->right, 0);
        printf(" )\n");
        break;
    case EXPR_TERN_BODY:
        printf(" varying types on a TERN return. You have ");
        type_print(lt, 0);
        printf("/ ");
        type_print(rt, 0);
        printf("\n");

        break;
    case EXPR_ARRAY_LITERAL:
        printf("non-homogeneous structures in a array");
        printf(" {");
        expr_print(e->left, 0);
        expr_print(e->right, 0);
        printf(" }\n");
        break;
        /*
    EXPR_GROUP,
    EXPR_FUNCTION_CALL,
    EXPR_ARG,
 */
    default:
        break;
    }
}

void special_stmt_error_handler(struct stmt *s, struct type *t)
{
    if (!s)
        return;
    MAIN_TYPEERROR_COUNT++;
    printf("type error: Dearest programmer, you ");

    switch (s->kind)
    {
    case STMT_IF:
    case STMT_IF_ELSE:
        printf("cannot evaluate a ");
        expr_print(s->expr, 0);
        printf(" (");
        expr_print(s->expr, 0);
        printf(" ). Type must be boolean\n ");
        break;
    // STMT_FOR
    case STMT_FOR:
        printf("must have INT; BOOLEAN; INT\n");
        printf("you have type");
        type_print(expr_typecheck(s->init_expr), 0);
        printf(";");
        type_print(expr_typecheck(s->expr), 0);
        printf(";");
        type_print(expr_typecheck(s->next_expr), 0);
        printf("\n");
        expr_print(s->init_expr, 0);
        printf(";");
        expr_print(s->expr, 0);
        printf(";");
        expr_print(s->next_expr, 0);
        printf("\n");

        break;
    case STMT_PRINT:
        break;
    case STMT_RETURN:
        break;
    default:
        break;
    }
}

void special_decl_error_handler(struct decl *d, struct type *t)
{
    if (!d)
        return;
    MAIN_TYPEERROR_COUNT++;
    printf("type error: Dearest programmer, you cannot");
    if (d->type->kind != TYPE_FUNCTION)
    {
        printf(" assign");
        type_print(t, 0);
        printf(" (");
        expr_print(d->value, 0);
        printf(") to");
        type_print(d->type, 0);
        printf(" (%s) \n", d->name);
    }
    else
    {
        printf(" return a");
        type_print(t, 0);

        printf("in a function(%s) that returns", d->name);
        type_print(d->type, 0);
        printf("\n");
    }
}
