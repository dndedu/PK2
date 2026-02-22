// Einbinden anderer Dateien(Bibliotheken)
#include <stdio.h>
#include "ggt.h"

// Methodenankündigung
// int ggt();

int main()
{
    printf("Enter two positive natural numbers to determine their greatest common divisor:");
    int number_one;
    scanf("%d",&number_one);
    int number_two;
    scanf("%d",&number_two);
    printf("%d\n", ggt(number_one, number_two));
    return 0;
}

/* // Methodendeklarationen

/*
Notes

    C Kommandozeilenbefehle
        Output von Assemblercode durch Compiler (Output.s)
            gcc -S ggt.c

        Erzeugen einer Objektdatei.o nach vollständigem Compilevorgang
            gcc -c ggt.c

        Programm kompilieren (ausführbares Zielprogramm, nach Binder/Linker)
            gcc {Dateiname.c} -o [{AusführbareDatei}]

        Aufruf des Programms
            ./{AusführbareDatei}

*/