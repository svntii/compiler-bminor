#include "scratch.h"
int scratch_alloc(void)
{
    for (int i = 0; i < 7; i++)
    {
        if (scratch[i])
        {
            return i;
        }
    }
    // print error
    exit(); // exit program
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
