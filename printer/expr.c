#include "expr.h"
#include "stmt.h"
#include "token.h"
#include "decl.h"
#include "type.h"
#include "param_list.h"

#include "token.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expr *expr_create(expr_t kind, struct expr *left, struct expr *right)
{
    struct expr *e = xmalloc(sizeof(struct expr)); // we have declared a pointer called e and allocated appropriate memory to that pointer
    e->kind = kind;
    e->left = left;
    e->right = right;
    return e;
}

struct expr *expr_create_add(struct expr *left, struct expr *right)
{
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
