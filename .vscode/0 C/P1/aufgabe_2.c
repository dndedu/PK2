#include <stdio.h>
#include "aufgabe_2.h"

void tabelle_zahlMultipliziertBisZehn()
{
    int von = 10, bis = 20;

    printf("Einmaleins\n");
    printf("Von: ");
    scanf("%d", &von);

    printf("Bis: ");
    scanf("%d", &bis);

    int mult = 1;
    while (mult <= 10)
    {
        int i;
        for (i = von; i <= bis; i++)
        {
            printf("%4d", mult * i);
        }
        printf("\n");
        mult++;
    }
    printf("\n");
}