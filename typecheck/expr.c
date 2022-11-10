#include "expr.h"
#include "scope.h"
#include "type.h"
#include "symbol.h"
#include "special.h"
#include "param_list.h"

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
    if (e)
    {
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
            printf("^");
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
            expr_print(e->right, tab);
            printf(" )");
            break;
        case EXPR_SUBSCRIPT:
            expr_print(e->left, tab);  // prints the name
            expr_print(e->right, tab); // prints the subscipts
            break;
        case EXPR_SUBSCRIPT_SUB:
            printf("[");
            expr_print(e->left, tab);
            printf("]");
            expr_print(e->right, tab);
            break;
        case EXPR_FUNCTION_CALL:
            expr_print(e->left, tab);
            printf("(");
            expr_print(e->right, tab);
            printf(")");
            break;
        case EXPR_ARG:
            expr_print(e->left, tab);
            if (e->right)
                printf(", ");
            expr_print(e->right, tab);
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
            // expr_print_array_literal(e, tab);
            expr_print(e->left, tab);
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
}

void expr_resolve(struct expr *e)
{
    if (!e)
        return;
    if (e->kind == EXPR_NAME)
    {
        e->symbol = scope_lookup_current(e->name); // # TODO confirm
    }
    else
    {
        expr_resolve(e->left);
        expr_resolve(e->right);
    }
}

struct type *expr_typecheck(struct expr *e)
{
    // recursive, post-order traversal of the expression tree
    if (!e)
        return 0;

    struct type *lt = expr_typecheck(e->left);
    struct type *rt = expr_typecheck(e->right);

    struct type *result;

    switch (e->kind)
    {
    case EXPR_INTEGER_LITERAL:
        result = type_create(TYPE_INTEGER, 0, 0, 0, 0);
        break;
    case EXPR_STRING_LITERAL:
        result = type_create(TYPE_STRING, 0, 0, 0, 0);
        break;
    case EXPR_BOOLEAN_LITERAL:
        result = type_create(TYPE_BOOLEAN, 0, 0, 0, 0);
        break;
    case EXPR_CHAR_LITERAL:
        result = type_create(TYPE_CHAR, 0, 0, 0, 0);
        break;
    case EXPR_ARRAY_LITERAL:
        // { 1 , 2, 3 }
        if (type_compare(lt, rt)) // lookback

        {
            result = type_copy(lt);
        }
        else
        {
            // error message
        }
        break;
    case EXPR_NAME:
        result = type_copy(e->symbol->type);
        break;
    case EXPR_EXP: // 2 ^ 4
    case EXPR_MOD: // 2 % 2
    case EXPR_ADD: // 1 + 1
    case EXPR_SUB: // 3 - 2
    case EXPR_MULT:
    case EXPR_DIV:

        if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER)
        {
            // error message
        }
        result = type_create(TYPE_INTEGER, 0, 0, 0, 0);
        break;

    case EXPR_OR:
    case EXPR_AND:
        if (lt->kind != TYPE_BOOLEAN || rt->kind != TYPE_BOOLEAN)
        {
        }
        result = type_create(TYPE_BOOLEAN, 0, 0, 0, 0);
        break;

    case EXPR_LT:
    case EXPR_LTE:
    case EXPR_GT:
    case EXPR_GTE:
        if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER)
        {
            special_error_handler();
        }
        result = type_create(TYPE_BOOLEAN, 0, 0, 0, 0);
        break;

    case EXPR_EQ:
    case EXPR_NEQ:

        if (!type_compare(lt, rt))
        {
            // print error
        }
        if (lt->kind == TYPE_VOID ||
            lt->kind == TYPE_ARRAY ||
            lt->kind == TYPE_FUNCTION)
        {
            /* display an error */
        }
        result = type_create(TYPE_BOOLEAN, 0, 0, 0, 0);
        break;
    case EXPR_POSIN:
    case EXPR_POSDEC:
        if (lt->kind == TYPE_INTEGER)
        {
            result = type_create(TYPE_INTEGER, 0, 0, 0, 0);
        }
        else
        {
            // print error
        }
        break;
    case EXPR_NEGATE:
        if (rt->kind == TYPE_INTEGER)
        {
            result = type_create(TYPE_INTEGER, 0, 0, 0, 0);
        }
        else
        {
            // print error
        }
        break;
    case EXPR_NOT:
        if (rt->kind == TYPE_BOOLEAN)
        {
            result = type_create(TYPE_BOOLEAN, 0, 0, 0, 0);
        }
        {
            // print error
        }

    case EXPR_GROUP:
        // think about
        break;
    case EXPR_SUBSCRIPT:
        if (lt->kind == TYPE_ARRAY)
        {
            if (rt->kind != TYPE_INTEGER)
            {
                /* error: index not an integer */
            }
            result = type_copy(lt->subtype);
        }
        else
        {
            /* error: not an array */
            /* but we need to return a valid type */
            result = type_copy(lt);
        }
        break;
    case EXPR_SUBSCRIPT_SUB:
        if (lt->kind == TYPE_ARRAY)
        {
            if (rt->kind != TYPE_INTEGER)
            {
                /* error: index not an integer */
            }
            result = type_copy(lt->subtype);
        }
        else
        {
            /* error: not an array */
            /* but we need to return a valid type */
            result = type_copy(lt);
        }
        break;
        break;
    case EXPR_FUNCTION_CALL:
        if (lt->kind == TYPE_FUNCTION && type_compare(lt->params->type, rt))
        {
            result = type_copy(lt->subtype);
        }
        else
        {
            // error message
        }

        break;
    case EXPR_ARG:

        break;
    case EXPR_ASSIGNMENT:

        if (type_compare(lt, rt))
        {
            result = type_copy(lt);
        }
        else
        {
            // print error
        }

        break;
    case EXPR_TERN:
        if (lt->kind == TYPE_BOOLEAN)
        {
            result = type_copy(rt);
        }
        else
        {
            // error message
        }
        break;
    default:
        break;
    }

    type_delete(lt);
    type_delete(rt);

    return result;
}
