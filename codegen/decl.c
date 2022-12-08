#include "decl.h"
#include "stmt.h"
#include "symbol.h"
#include "scope.h"
#include "type.h"
#include "expr.h"
#include "argument.h"
#include "param_list.h"
#include "special.h"

extern int MAIN_RESOLVEERROR_COUNT;
extern FILE *output_file;

int DECL_ARRAY_COUNT = 0;

struct decl *decl_create(char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next)
{
    struct decl *d = special_xmalloc(sizeof(*d));
    d->name = name;
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;
    return d;
}

void decl_print(struct decl *d, int tab)
{
    if (d)
    {
        printf("%s", d->name);
        printf(":");
        type_print(d->type, tab);
        if (d->value)
        {
            printf(" = ");
        }
        expr_print(d->value, tab);
        if (d->type->kind == TYPE_FUNCTION && d->code)
        {
            printf(" = ");
        }
        stmt_print(d->code, tab);
        if (d->value || !d->code)
        {
            printf(";");
        }
        printf("\n");
        special_tabprinter(tab);
        decl_print(d->next, tab);
    }
}

void decl_resolve(struct decl *d)
{
    if (!d)
        return;
    // created a symbol for d

    d->symbol = symbol_create(scope_level() > 1 ? SYMBOL_LOCAL : SYMBOL_GLOBAL, d->type, d->name, 0, 0);

    if (d->type->kind == TYPE_FUNCTION && !d->code)
    {
        d->symbol->prototype = 1;
    }

    // x:integer; or y:integer = 10;
    struct symbol *s = scope_lookup_current(d->name);

    if (s && !type_compare(s->type, d->type) && s->prototype)
    {
        // check if it is a prototype and the types match
        MAIN_RESOLVEERROR_COUNT++;
        printf("resolve error: the defintion of %s does not match its prototype, please double check the types\n", s->name);
    }

    expr_resolve(d->value);
    scope_bind(d->name, d->symbol);

    // main: function void = { ... }

    if (d->code)
    {
        symbol_local_count_reset();
        scope_enter();
        param_list_resolve(d->type->params);
        stmt_resolve(d->code);
        scope_exit();
    }
    // GOTO next decl
    decl_resolve(d->next);
    return;
}

void decl_typecheck(struct decl *d)
{
    /*char *name;           test2
    struct type *type;      function boolean
    struct expr *value;     0
    struct stmt *code;      0
    struct symbol *symbol;
    struct decl *next;
    */

    if (!d)
        return;

    if (d->value)
    {
        struct type *t = expr_typecheck(d->value);
        if (d->symbol->type->kind == TYPE_AUTO)
        {
            d->symbol->type = type_copy(t);
            d->type = d->symbol->type;
        }
        if (d->symbol->type->kind == TYPE_ARRAY)
        {
            /* code typechecking arrays */
            if (!type_compare(t, d->symbol->type->subtype))
            {
                special_decl_error_handler(d, t);
            }

            struct type *inside_array_type = expr_typecheck(d->type->inside_array);
            if (inside_array_type->kind != TYPE_INTEGER)
            {
                special_decl_error_handler(d, inside_array_type);
            }
        }
        else if (!type_compare(t, d->symbol->type))
        {
            special_decl_error_handler(d, t);
        }
    }

    if (d->code)
    {
        if (!param_list_compare(d->symbol->type->params, d->type->params))
        {
            special_decl_error_handler(d, d->symbol->type);
        }
        stmt_typecheck(d->code, d->symbol);
        d->symbol->type = type_copy(d->type);
    }

    decl_typecheck(d->next);
}

void decl_codegen(struct decl *d)
{
    if (!d)
        return;
    if (d->symbol->kind == SYMBOL_GLOBAL)
    {
        fprintf(output_file, ".globl %s\n", d->name);
        switch (d->type->kind)
        {
        case TYPE_BOOLEAN:
            if (!d->value)
            {
                fprintf(output_file, "%s:\t .quad 0\n", d->name);
            }
            else
            {
                fprintf(output_file, "%s:\t .quad %d\n", d->name, (int)d->value->literal_value);
            }

            break;
        case TYPE_CHAR:
            if (!d->value)
            {
                fprintf(output_file, "%s:\t .quad 0\n", d->name);
            }
            else
            {
                fprintf(output_file, "%s:\t .quad %d\n", d->name, (int)d->value->literal_value);
            }
            break;
        case TYPE_INTEGER:
            if (!d->value)
            {
                fprintf(output_file, "%s:\t .quad 0\n", d->name);
            }
            else
            {
                fprintf(output_file, "%s:\t .quad %d\n", d->name, d->value->literal_value);
            }

            break;
        case TYPE_STRING:
            if (!d->value)
            {
                fprintf(output_file, "%s:\t .quad 0\n", d->name);
            }
            else
            {
                fprintf(output_file, "%s:\t .string %s\n", d->name, d->value->string_literal);
            }
            break;
        case TYPE_ARRAY:
            fprintf(output_file, "%s:\n", d->name);
            decl_arraycodegen(d->value);
            break;
        case TYPE_FUNCTION:
            fprintf(output_file, "%s:\n", d->name);
            // preamble
            fprintf(output_file, "\tpushq %%rbp\n");
            fprintf(output_file, "\tmovq %%rsp, %%rbp\n");
            fprintf(output_file, "\n");
            // param_print
            struct param_list *temp = d->symbol->type->params;

            int offset = -8;
            while (temp)
            {
                offset = offset + 8;
                int a = argument_alloc();
                fprintf(output_file, "\tpushq %s\n", argument_name(a));
                temp = temp->next;
            }

            fprintf(output_file, "\n\tsubq $%d, %%rsp\n", offset); // allocate for local variable
            fprintf(output_file, "\n");

            //  OUTRO
            fprintf(output_file, "\tpushq %%rbx\n");
            fprintf(output_file, "\tpushq %%r12\n");
            fprintf(output_file, "\tpushq %%r13\n");
            fprintf(output_file, "\tpushq %%r14\n");
            fprintf(output_file, "\tpushq %%r15\n");
            fprintf(output_file, "\n");

            int inset = 8;
            fprintf(output_file, "\tmovq -8(%%rbp), %%rbx\n");
            while (offset > 0)
            {
                inset = inset + 8;
                offset = offset - 8;
                int b = argument_find();
                fprintf(output_file, "\tmovq -%d(%%rbp), %s\n", inset, argument_name(b));
            }
            fprintf(output_file, "\n");

            stmt_codegen(d->code);

            // postamble
            fprintf(output_file, "\tpopq %%r15\n");
            fprintf(output_file, "\tpopq %%r14\n");
            fprintf(output_file, "\tpopq %%r13\n");
            fprintf(output_file, "\tpopq %%r12\n");
            fprintf(output_file, "\tpopq %%rbx\n");

            fprintf(output_file, "\n");
            // param pop
            fprintf(output_file, "\tmovq %%rbp, %%rsp\n");
            fprintf(output_file, "\tpopq %%rbp\n");
            fprintf(output_file, "\tret\n");

            break;
        default:
            break;
        }
    }
    else if (d->symbol->kind == SYMBOL_LOCAL)
    {
        switch (d->type->kind)
        {
        case TYPE_BOOLEAN:
            expr_codegen(d->value);
            break;
        case TYPE_CHAR:
            expr_codegen(d->value);

            break;
        case TYPE_INTEGER:
            expr_codegen(d->value);

            break;
        case TYPE_STRING:
            fprintf(output_file, ".data\n");
            fprintf(output_file, ".%s:\t .string %s\n", d->name, d->value->string_literal);
            fprintf(output_file, ".text\n");

            break;
        default:
            break;
        }
    }
    else
    {
    }

    decl_codegen(d->next);
}

void decl_arraycodegen(struct expr *e)
{

    if (!e)
    {
        return;
    }
    switch (e->kind)
    {
    case EXPR_INTEGER_LITERAL:
        fprintf(output_file, "\t.quad %d\n", e->literal_value);

        break;
    case EXPR_BOOLEAN_LITERAL:
        fprintf(output_file, "\t.quad %d\n", e->literal_value);

        break;
    case EXPR_CHAR_LITERAL:
        fprintf(output_file, "\t.quad %d\n", e->literal_value);

        break;
    case EXPR_STRING_LITERAL:

        printf("%s", e->string_literal);
        break;

    case EXPR_ARRAY_LITERAL:
        // expr_print_array_literal(e, tab);
        decl_arraycodegen(e->left);
        decl_arraycodegen(e->right);
        break;
    case EXPR_NAME:

        printf("%s", e->name);
        break;
    case EXPR_ARG:
        decl_arraycodegen(e->left);
        decl_arraycodegen(e->right);
    }
}