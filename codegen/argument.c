#include "argument.h"
#include <stdlib.h>

int arguments[] = {0, 0, 0, 0, 0, 0};
char *arguments_register[] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};

int argument_alloc(void)
{
    for (int i = 0; i < 6; i++)
    {
        if (arguments[i] == 0)
        {
            arguments[i] = 1;
            return i;
        }
    }
    // print error
    exit(-1); // exit program
}
void argument_free(int r)
{
    if (r < 0 || r > 6)
    {
        // if r is out bounds
    }
    arguments[r] = 0;
}
const char *argument_name(int r)
{
    if (r < 0 || r > 6)
    {
        // if r is out bounds
    }
    return arguments_register[r];
}

int argument_find()
{
    int i = 0;
    while (i < 6)
    {
        if (arguments[i] == 1)
        {
            argument_free(i);
            return i;
        }
        i++;
    }
}