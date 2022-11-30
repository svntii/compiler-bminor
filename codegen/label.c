#include "label.h"
#include <stdio.h>

int label_create()
{
    LABEL++;
    return LABEL;
}

const char *label_name(int label)
{
    char str[BUFSIZ];
    sprintf(str, ".L%d", label);
    return str;
}