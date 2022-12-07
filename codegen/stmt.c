#include "type.h"
#include "symbol.h"
#include "stmt.h"
#include "expr.h"
#include "decl.h"
#include "scope.h"
#include "special.h"
#include "label.h"
#include "scratch.h"
extern int MAIN_RESOLVEERROR_COUNT;
extern FILE *output_file;
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

void stmt_resolve(struct stmt *s)
{
    if (!s)
        return;
    switch (s->kind)
    {
    case STMT_BLOCK:
        // { ....  }

        scope_enter();
        stmt_resolve(s->body);
        scope_exit();
        break;
    case STMT_DECL:
        // x: integer = 10;
        decl_resolve(s->decl);
        break;
    case STMT_EXPR:
        // a = 1; z  = 1 + 1; g(1);
        expr_resolve(s->expr);
        break;
    case STMT_IF_ELSE:
        // if EXPR then BODY
        expr_resolve(s->expr);
        stmt_resolve(s->body);
        break;
    case STMT_IF:
        // if EXPR then BODY else ELSE_BODY
        expr_resolve(s->expr);
        stmt_resolve(s->body);
        stmt_resolve(s->else_body);
        break;
    case STMT_FOR:
        // for(INIT_EXPR;EXPR;NEXT_EXPR){ BODY }
        expr_resolve(s->init_expr);
        expr_resolve(s->expr);
        expr_resolve(s->next_expr);
        stmt_resolve(s->body);
        break;
    case STMT_PRINT:
        // print EXPR
        expr_resolve(s->expr);
        break;
    case STMT_RETURN:
        // return EXPR
        expr_resolve(s->expr);
        break;
    case STMT_WHILE:
        // while(EXPR){BODY}
        expr_resolve(s->expr);
        stmt_resolve(s->body);
        break;

    default:
        MAIN_RESOLVEERROR_COUNT++;
        fprintf(stderr, "Resolve Error: INCORRECT TYPE");
        break;
    }

    stmt_resolve(s->next);
}

void stmt_typecheck(struct stmt *s, struct symbol *return_type)
{
    if (!s)
        return;

    struct type *t;
    switch (s->kind)
    {
    case STMT_EXPR:
        t = expr_typecheck(s->expr);
        type_delete(t);
        break;
    case STMT_DECL:
        decl_typecheck(s->decl);
        break;
    case STMT_IF_ELSE:
        t = expr_typecheck(s->expr);
        if (t->kind != TYPE_BOOLEAN)
        {
            special_stmt_error_handler(s, t);
        }
        type_delete(t);
        stmt_typecheck(s->body, return_type);
        stmt_typecheck(s->else_body, return_type);
        break;
    case STMT_IF:
        t = expr_typecheck(s->expr);
        if (t->kind != TYPE_BOOLEAN)
        {
            special_stmt_error_handler(s, t);
        }
        type_delete(t);
        stmt_typecheck(s->body, return_type);
        break;
    case STMT_FOR:
        t = expr_typecheck(s->init_expr);
        if (t)
        {
            type_delete(t);
        }

        t = expr_typecheck(s->expr);
        if (t)
        {
            if (!t || t->kind != TYPE_BOOLEAN)
            {
                special_stmt_error_handler(s, t);
            }

            type_delete(t);
        }

        t = expr_typecheck(s->next_expr);
        if (t)
        {
            type_delete(t);
        }

        stmt_typecheck(s->body, return_type);
    case STMT_PRINT:
        expr_typecheck(s->expr);
        break;
    case STMT_BLOCK:
        stmt_typecheck(s->body, return_type);
        break;
    case STMT_RETURN:
        struct type *r = NULL;

        if (s->expr)
        {
            r = type_copy(expr_typecheck(s->expr));
        }
        else
        {
            // if not an expression type create void
            r = type_create(TYPE_VOID, 0, 0, 0, 1, 0);
        }

        if (return_type->type->subtype->kind == TYPE_AUTO)
        {
            return_type->type = type_copy(r);
        }
        else if (!type_compare(r, return_type->type->subtype))
        {

            special_stmt_error_handler(s, r);
            type_print(return_type->type, 0);
        }

        break;
    default:
        break;
    }
    stmt_typecheck(s->next, return_type);
}

void stmt_codegen(struct stmt *s)
{
    if (!s)
        return;

    switch (s->kind)
    {
    case STMT_DECL:
        decl_codegen(s->decl);
        break;
    case STMT_EXPR:
        expr_codegen(s->expr);
        scratch_free(s->expr->reg);
        break;
    case STMT_IF_ELSE:
    {
        int else_label = label_create();
        int done_label = label_create();
        expr_codegen(s->expr);
        fprintf(output_file, "\tCMP $0, %s\n", scratch_name(s->expr->reg));
        scratch_free(s->expr->reg);
        fprintf(output_file, "\tJE %s\n", label_name(else_label));
        stmt_codegen(s->body);
        fprintf(output_file, "\tJMP %s\n", label_name(done_label));
        fprintf(output_file, "%s:\n", label_name(else_label));
        stmt_codegen(s->else_body);
        fprintf(output_file, "\t%s:\n", label_name(done_label));
        break;
    }
    case STMT_IF:
    {
        int done_label = label_create();
        expr_codegen(s->expr);
        fprintf(output_file, "\tCMP $0, %s\n", scratch_name(s->expr->reg));
        scratch_free(s->expr->reg);
        fprintf(output_file, "\tJE %s\n", label_name(done_label));
        stmt_codegen(s->body);
        fprintf(output_file, "\tJMP %s\n", label_name(done_label));
        fprintf(output_file, "\t%s:\n", label_name(done_label));
        break;
    }
    case STMT_FOR:
        int top_label = label_create();
        int done_label = label_create();
        if (s->init_expr)
        {
            expr_codegen(s->init_expr);
            scratch_free(s->init_expr->reg);
        }
        fprintf(output_file, "\t%s:\n", label_name(top_label));
        if (s->expr)
        {
            /* code */
            expr_codegen(s->expr);
            fprintf(output_file, "\tCMP $0, %s\n", scratch_name(s->expr->reg));
            scratch_free(s->expr->reg);
        }
        else
        {
            fprintf(output_file, "\tCMP $0, $0\n");
        }

        fprintf(output_file, "\tJE %s\n", label_name(done_label));
        stmt_codegen(s->body);
        if (s->next_expr)
        {
            expr_codegen(s->next_expr);
            scratch_free(s->next_expr->reg);
        }
        fprintf(output_file, "\tJMP %s\n", label_name(done_label));
        fprintf(output_file, "\t%s:\n", label_name(done_label));
        break;
    case STMT_PRINT:
        expr_codegen(s->expr);
        break;
    case STMT_RETURN:
        /*A return statement must evaluate an expression, move it into the des-
    ignated register for return values %rax, and then jump to the function epi-
    logue, which will unwind the stack and return to the call point*/
        expr_codegen(s->expr);
        fprintf(output_file, "\tmovq %s, %%rax\n", scratch_name(s->expr->reg));
        // printf("JMP .%s_epilogue\n", function_name);
        fprintf(output_file, "\tpopq %%r15\n");
        fprintf(output_file, "\tpopq %%r14\n");
        fprintf(output_file, "\tpopq %%r13\n");
        fprintf(output_file, "\tpopq %%r12\n");

        fprintf(output_file, "\tmovq %%rbp, %%rsp\n");
        fprintf(output_file, "\tpopq %%rbp\n");
        fprintf(output_file, "\tret\n");
        fprintf(output_file, "\nanything after is ommitted in code\n");

        scratch_free(s->expr->reg);
        break;
    case STMT_WHILE:
        break;
    case STMT_BLOCK:
        stmt_codegen(s->body);
        break;
    default:
        break;
    }
    stmt_codegen(s->next);
}
