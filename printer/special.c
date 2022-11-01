#include "special.h"

void *special_xmalloc(size_t size)
{
    void *p = (void *)malloc(size);
    if (!p)
        abort();
    return p;
}
void special_tabprinter(int tab)
{
    for (int i = 0; i < tab; i++)
    {
        printf("    ");
    }
}