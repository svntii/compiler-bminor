#include "label.h"
#include <stdio.h>
#include <stdlib.h>
int LABEL = 0;
int label_create()
{
    LABEL++;
    return LABEL;
}

const char *label_name(int label)
{
    char *str = malloc(BUFSIZ);
    sprintf(str, ".L%d", label);
    return str;
}