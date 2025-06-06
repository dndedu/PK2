#include <stdio.h>
#include "a1.h"

void tabelle_dynamisch_asciiZeichen()
{
    int s = 10, i;
    printf("Spalten: ");
    scanf("%d", &s);
    for (i = 32; i <= 126; i++)
    {
        if (i != 32 && (i - 32) % s == 0)
        {
            printf("\n");
        }
        printf("%3d %c ", i, i);
    }
    printf("\n");
}