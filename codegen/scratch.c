#include "scratch.h"
#include <stdlib.h>

int scratch[] = {0, 0, 0, 0, 0, 0, 0};
char *scratch_register[] = {"%rbx", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15"};

int scratch_alloc(void)
{
    for (int i = 0; i < 7; i++)
    {
        if (scratch[i] == 0)
        {
            scratch[i] = 1;
            return i;
        }
    }
    // print error
    exit(-1); // exit program
}
void scratch_free(int r)
{
    if (r < 0 || r > 7)
    {
        // if r is out bounds
    }
    scratch[r] = 0;
}
const char *scratch_name(int r)
{
    if (r < 0 || r > 7)
    {
        // if r is out bounds
    }
    return scratch_register[r];
}
