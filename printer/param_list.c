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

struct param_list *param_list_create(char *name, struct type *type, struct symbol *symbol, struct param_list *next)
{
    struct param_list *p = xmalloc(sizeof(struct param_list));
    p->name = name;
    p->type = type;
    p->symbol = symbol;
    p->next = next;
    return p;
}