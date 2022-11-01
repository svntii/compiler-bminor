#include "stdlib.h"

void *xmalloc(size_t size)
{
    void *p = (void *)malloc(size);
    if (!p)
        abort();
    return p;
}
