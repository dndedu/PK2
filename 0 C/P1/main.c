#include <stdio.h>
#include "aufgabe_1.h"
#include "aufgabe_2.h"
#include "aufgabe_3.h"

int main()
{
    //A1
    tabelle_dynamisch_asciiZeichen();
    //A2
    tabelle_zahlMultipliziertBisZehn();
    //A3.1
    // int decimal;
    // printf("Enter a whole number:\n");
    // scanf("%d", &decimal);
    // wholeNumber_toBinary(decimal);
    //A3.2, ohne Parameter, interne Abfrage der Zahl; Header-Datei muss entsprechend umkommentiert werden, da es in C keine Überladung gibt
    wholeNumber_toBinary();
    return 0;
}