#include <stdio.h>
#include "stack.h"

int main()
{
    long i;
    for (i = 1; i <= 10; i++)
    {
        push(i);
    }

    while ((i = pop()) != -1)
    {
        printf("%ld\n", i);
    }

    return 0;
}