// Einbinden anderer Dateien(Bibliotheken)
#include <stdio.h>
#include "ggt.h"

// Methodenankündigung
// int ggt();

int main()
{
    printf("%d", ggt(7, 28));
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