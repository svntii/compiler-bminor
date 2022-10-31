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

struct stmt *stmt_create(stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next)
{
    struct stmt *s = xmalloc(sizeof(*s));
    s->kind = kind;
    s->decl = decl;
    s->init_expr = init_expr;
    s->next_expr = next_expr;
    s->body = body;
    s->else_body = else_body;
    s->next = next;
}

struct stmt *stmt_create_decl(struct decl *decl)
{
    struct stmt *s = stmt_create(STMT_DECL, decl, 0, 0, 0, 0, 0, 0);
    return s;
}
struct stmt *stmt_create_expr(struct expr *expr)
{
    struct stmt *s = stmt_create(STMT_EXPR, 0, 0, expr, 0, 0, 0, 0);
    return s;
}

struct stmt *stmt_create_if_else(struct expr *expr, struct stmt *body, struct stmt *else_body)
{
    struct stmt *s = stmt_create(STMT_IF_ELSE, 0, 0, expr, 0, body, else_body, 0);
    return s;
}

struct stmt *stmt_create_if(struct expr *expr, struct stmt *body)
{
    struct stmt *s = stmt_create(STMT_IF, 0, 0, expr, 0, body, 0, 0);
    return s;
}

struct stmt *stmt_create_for(struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body)
{
    struct stmt *s = stmt_create(STMT_FOR, 0, init_expr, expr, next_expr, body, 0, 0);
    return s;
}

struct stmt *stmt_create_print(struct expr *expr)
{
    struct stmt *s = stmt_create(STMT_PRINT, 0, 0, expr, 0, 0, 0, 0);
    return s;
}
struct stmt *stmt_create_return(struct expr *expr)
{
    struct stmt *s = stmt_create(STMT_RETURN, 0, 0, expr, 0, 0, 0, 0);
    return s;
}
struct stmt *stmt_create_while(struct expr *expr, struct stmt *body)
{
    struct stmt *s = stmt_create(STMT_FOR, 0, 0, expr, 0, body, 0, 0);
    return s;
}
struct stmt *stmt_create_block(struct stmt *body)
{
    struct stmt *s = stmt_create(STMT_BLOCK, 0, 0, 0, 0, body, 0, 0);
    return s;
}
