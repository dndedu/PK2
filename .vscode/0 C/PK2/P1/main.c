#include <stdio.h>
#include "aufgabe_1.h"
#include "aufgabe_2.h"
#include "aufgabe_3.h"

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