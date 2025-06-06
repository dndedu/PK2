#include <stdio.h>
#include "a3.h"

void wholeNumber_toBinary(int x)
{
    int binary[16];
    for (int i = 0; i < 16; i++)
    {
        binary[i] = 0;
    }

    int i = 0;
    while (x > 0)
    {
        binary[i++] = x % 2;
        x /= 2;
    }
    for (i = 15; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    printf("\n");
}