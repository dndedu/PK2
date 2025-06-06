#include <stdio.h>
#include "a1.h"
#include "a2.h"
#include "a3.h"

int main()
{
    tabelle_dynamisch_asciiZeichen();
    tabelle_zahlMultipliziertBisZehn();

    int decimal;
    printf("Enter a whole number:\n");
    scanf("%d", &decimal);
    wholeNumber_toBinary(decimal);
    return 0;
}