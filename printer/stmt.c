#include "expr.h"
#include "stmt.h"
#include "decl.h"
#include "special.h"
#include "stdio.h"

struct stmt *stmt_create(stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next)
{
    struct stmt *s = special_xmalloc(sizeof(*s));
    s->kind = kind;
    s->decl = decl;
    s->init_expr = init_expr;
    s->expr = expr;
    s->next_expr = next_expr;
    s->body = body;
    s->else_body = else_body;
    s->next = next;
}

void *stmt_print(struct stmt *s, int tab)
{
    if (s)
    {
        switch (s->kind)
        {
        case STMT_DECL:
            decl_print(s->decl, tab);
            printf("\n");
            special_tabprinter(tab);
            break;
        case STMT_EXPR:
            expr_print(s->expr, tab);
            printf(";");
            printf("\n");
            special_tabprinter(tab);
            break;
        case STMT_IF_ELSE:
            printf("if (");
            expr_print(s->expr, tab);
            printf(")\n");
            special_tabprinter(tab + 1);
            stmt_print(s->body, tab + 1);
            printf("\n");
            special_tabprinter(tab);
            printf("else");
            printf("\n");
            special_tabprinter(tab + 1);
            stmt_print(s->else_body, tab + 1);
            break;
        case STMT_IF:
            printf("if (");
            expr_print(s->expr, tab);
            printf(")\n");
            special_tabprinter(tab + 1);
            stmt_print(s->body, tab + 1);
            break;
        case STMT_FOR:
            printf("for (");
            expr_print(s->init_expr, tab);
            printf("; ");
            expr_print(s->expr, tab);
            printf("; ");
            expr_print(s->next_expr, tab);
            printf(" )");
            printf("\n");
            special_tabprinter(tab + 1);
            stmt_print(s->body, tab + 1);

            break;
        case STMT_PRINT:
            printf("print ");
            expr_print(s->expr, tab);
            printf(";");
            printf("\n");
            special_tabprinter(tab);
            break;
        case STMT_RETURN:
            printf("return ");
            expr_print(s->expr, tab);
            printf(";");
            printf("\n");
            special_tabprinter(tab);
            break;
        case STMT_WHILE:
            break;
        case STMT_BLOCK:
            printf("\n");
            special_tabprinter(tab);
            printf("{\n");
            special_tabprinter(tab + 1);
            stmt_print(s->body, tab + 1);
            printf("\n");
            special_tabprinter(tab);
            printf("}\n");
            special_tabprinter(tab);
            break;

        default:
            break;
        }

        stmt_print(s->next, tab);
    }
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
