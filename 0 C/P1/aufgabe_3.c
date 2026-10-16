#include <stdio.h>
#include "aufgabe_3.h"

void wholeNumber_toBinary()
{
    int decimal;
    printf("Enter a whole number (which will be displayed in its binary form):\n");
    scanf("%d", &decimal);

    int binary[16];
    for (int i = 0; i < 16; i++)
    {
        binary[i] = 0;
    }

    int i = 0;
    while (decimal > 0)
    {
        binary[i++] = decimal % 2;
        decimal /= 2;
    }
    for (i = 15; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// void wholeNumber_toBinary(int x)
// {
//     int binary[16];
//     for (int i = 0; i < 16; i++)
//     {
//         binary[i] = 0;
//     }

//     int i = 0;
//     while (x > 0)
//     {
//         binary[i++] = x % 2;
//         x /= 2;
//     }
//     for (i = 15; i >= 0; i--)
//     {
//         printf("%d", binary[i]);
//     }
//     printf("\n");
// }