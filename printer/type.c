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

struct type *type_create(type_t kind, struct type *subtype, struct param_list *params)
{
    struct type *t = xmalloc(sizeof(struct type));
    t->kind = kind;
    t->subtype = subtype;
    t->params = params;
    return t;
}