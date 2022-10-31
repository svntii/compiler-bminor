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

void *xmalloc(size_t size)
{
    void *p = (void *)malloc(size);
    if (!p)
        abort();
    return p;
}
