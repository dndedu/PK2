#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h> //Bibliothek libc.a für strcpy (Zuweisung eines Wertes zu einer Zeichenkette(char-Array) außerhalb der Definition)
#include <stdlib.h> //Speicherverwaltung

#include "utilities.h"

int main(int argc, char const *argv[])
{
    // // DataType Properties
    printf("Der Typ char benoetigt %d Byte\n", sizeof(char));
    printf("Wertebereich von char: %d, ... ,%d\n",
           CHAR_MIN, CHAR_MAX);

    printf("Der Typ short_int benoetigt %d Byte\n", sizeof(short int));
    printf("Wertebereich von short_int: %d, ... ,%d\n",
           SHRT_MIN, SHRT_MAX);
    printf("Wertebereich von unsigned short_int: 0, ..., %d\n", USHRT_MAX);

    printf("Der Typ int benoetigt %d Byte\n", sizeof(int));
    printf("Wertebereich von int: %d, ... ,%d\n",
           INT_MIN, INT_MAX);

#define FEHLERMELDUNG(text) fprintf(stderr, text)
    FEHLERMELDUNG("test\n");

    union FloatToInt
    {
        float f;
        int i;
    };
    union FloatToInt u;
    u.f = 3.14f;
    printf("Bits von float als int: %d\n", u.i); // Bits von 3.14 als int darstellen

    printf("value of argc: %d\n", argc);

    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    /*TODO
        C-VL durchgehen und, sofern nicht in den Praktikumsaufgaben behandelt mit struct, union, typedef etc. umgehen lernen/programmieren
    */

    // // Logische Operatoren
    // long a = 64, b = 32, c;
    // c = a | b;
    // b = a << 1;
    // printf("%d, %d\n", c, b);

    // // switch-case, parameter typ input, goto, getchar, putchar
    // int s_i = 1;
    // double s_d = 1.2;
    // // char s_c = 'A';
    // printf("Enter a single char:");
    // char s_c = getchar();
    // char s_s[] = "Hallo";
    // switch (s_c)
    // {
    // case 'A':
    //     // printf("1\n");
    //     putchar(s_c);
    //     printf("\r1\n");
    //     putchar(s_c);
    //     goto ziel;
    //     break;
    // case 61: // duplicate case value bei 65
    // ziel:
    //     printf("2\n");
    //     break;
    // default:
    //     break;
    // }

    // // Ein-&Ausgabe
    // char s_s[] = "Hallo Welt!";
    // printf("%s\n", s_s);
    // // Pointer auf char
    // char *s_a;
    // // String (pointer auf char-Array) eingelesen; Null-Byte bei %s automatisch gesetzt
    // scanf("%s", s_a);
    // //
    // strcpy(s_s, s_a);
    // printf("%s\n", s_s);
    // printf("W aus Hallo Welt (wenn neuer String max. 5 Zeichen): %c", s_s[6]);

    // // Structs
    // struct student
    // {
    //     char nachname[50];
    //     char vorname[50];
    //     char geburtsdatum[11]; // 1987-xx-xx
    //     int matrikelnummer;
    // } student_einzeln, studenten_fhDortmund[20000];
    // strcpy(studenten_fhDortmund[0].nachname, "Domanski");
    // strcpy(studenten_fhDortmund[0].vorname, "Daniel");
    // strcpy(studenten_fhDortmund[0].geburtsdatum, "1987-03-29");
    // studenten_fhDortmund[0].matrikelnummer = 7088916;
    // studenten_fhDortmund[1].nachname = "Test"; // expression must be a modifiable lvalue

    // // Unions
    // union zeitangabe
    // {
    //     int uhrzeit;
    //     char tageszeit[11]; // morgen, vormittag, mittag, nachmittag, abend, nacht
    // };
    // union zeitangabe zA;
    // zA.uhrzeit = INT_MAX;
    // for (int i = 0; i < sizeof(zA.tageszeit); i++)
    // {
    //     printf("Byte %i, Wert: %i\n", i, zA.tageszeit[i]);
    // }
    // // aus VL
    // union konvertierung
    // {
    //     int x;
    //     unsigned char bytes[sizeof(int)];
    // };
    // union konvertierung zahl;
    // zahl.x = 20000;
    // printf("%i\n", sizeof(zahl));
    // printf("%i\n", sizeof(zahl.x));
    // printf("%i\n", sizeof(zahl.bytes));
    // for (int i = 0; i < sizeof(zahl); i++)
    // {
    //     printf("Byte %i, Wert: %i\n", i, zahl.bytes[i]);
    // }
    // // 0:  100 1110
    // // 1: 0010 0000

    // // Enums
    // enum Wochentag
    // {
    //     MONTAG = 1,
    //     DIENSTAG,
    //     MITTWOCH,
    //     DONNERSTAG = 10,
    //     FREITAG,
    //     SAMSTAG,
    //     SONNTAG
    // } wt;
    // wt = FREITAG;
    // printf("%i", wt);

    // // typedef
    // typedef struct
    // {
    //     char strasse[1];
    //     int hausnummer;
    //     char plz[1];
    //     char stadt[1];
    // } adresse_t, adressenArray_t[10];
    // adresse_t adresse[100];
    // adressenArray_t adressen[100]; // 100 pointer auf adressenArray_t, welche jeweils 10 adresse_t speichern
    // printf("%i\n", sizeof(adressen));
    // adressen[0]->hausnummer = 8;

    // // Sichtbarkeit
    // int x = 1;
    // {
    //     int x = 2;
    //     printf("%d\n", x);
    // }
    // printf("%d\n", x);

    // // Pointer
    // int feld[100];
    // feld[5] = 55;
    // int *ptr;
    // printf("sizeof(feld): %d\n", sizeof(feld));
    // printf("sizeof(ptr): %d\n", sizeof(ptr));
    // ptr = feld;
    // printf("%d\n", *(ptr + 5));
    // printf("%d\n", (ptr)[5]);
    // // zur oberen struct student-Struktur
    // struct student *ptrs = &student_einzeln;
    // ptrs->geburtsdatum = "Test";
    // strcpy((*ptrs).geburtsdatum, "Test\0");
    // printf("%s\n", (*ptrs).geburtsdatum);
    // // Funktionszeiger
    // void (*pS)(char[]);
    // pS = &printString;
    // (*pS)("Test");

    // // Speicherverwaltung, malloc, calloc
    // int *a;
    // a = (int *)calloc(10, 3);
    // printf("%d\n", *(a + 10));

    // // S.100 String kopieren
    //     const char *original = "C macht Spass.";
    //     char *duplikat;
    //     // duplikat = original;
    //     string_copy(duplikat, original);
    //     printf("%s\n", duplikat);

    // // print argumentlist of main method
    //     print_mainArguments(argc, argv);

    return 0;
}

/*
Datentypen
    bool in Form von int 0 = falsch, 1 = true (Logische Operatoren liefern für true eine 1)

    Wertebereichsmember/-eigenschaften/-properties
        INT_MIN, INT_MAX

    Zeichenkette/String
        mit Nullbyte 0000 0000 terminieren
            automatisch oder manuell mit \0

    struct [struct_name] {struct_definition} [struct_variables];
        Synonym: Records
        bei Definition keine Speicherreservierung
        Schachtelung möglich
        fachliche Sicht
    union
        Synonym: Varianten
        Attribute übereinander gespeichert
        immer nur ein Attribut abgespeichert
        längste Attribut bestimmt Gesamtlänge
    enum
        Synonym: Aufzählung
        Kombination mehrerer Konstanten zu neuem Typ
        default-Startwert 0
        Startwert und folgende Werte änderbar
        Inkrement pro folgendem Element um 1
    typedef
        neuer Name für bestehende Datentypen
        Zusatz/Anhang an Variablennamen zur Kennzeichnung variablenname_t
    pointer
        Wert ist Adresse
        Definition
            typ *name
        Zuweisung einer Adresse
            bspw. mittels unärem Adressoperator &
        Dereferenzierung / Zugriff auf Wert
            mittels *
        Funktionspointer
            return_type (*functionPointerName) (parameterList);

Präprozessordirektiven
    #include <standard.h>
    #include "eigen.h"
    #define toBeReplaced newValue
    #if value sequence #endif
    __FILE__
    __LINE__

Speicherverwaltung
    statisch
        globale Variablen und Konstanten
    Stack
        lokale Variablen
        frame-Erzeugung durch Methodenaufruf
    Heap
        vom Programmierer zur Laufzeit dynamisch verwaltet
        void *malloc(size_t size);
            liefert NULL oder Zeiger auf erstes Byte des reservierten Bereiches
                casten/umwandeln in passenden Datentyp
        void *calloc( size_count, sizeInBytes/sizeof(datatype) );
            initialisieren des Speicherbereiches mit 0
        free(zeiger);
            nur auf zuvor reservierte Speicherbereiche anwenden

Speicherklassen
    auto
        default
        Blocksichtbarkeit
    register
        Empfehlung an Compiler
    static (local)
        gesamte Laufzeit
    extern
        nur bei Deklaration einer globalen Variablen
        keine Reservierung von Speicherplatz
        Hinweis auf Variablendefinition in anderer Datei
    static (global)
        nur in Programmdatei in der diese definiert ist

Methoden
    Konsolenausgabe
        printf(zeichenkettenliteral, wert);
            %d/i; %ld/li; %f/g; %c; char *, %s
        Einlesen einzelnes Zeichen
            getchar();
        putchar(zeichen);
            kein Zeilenumbruch \n
        scanf(zeichenkettenliteral, &speicherort);
            %d/i; %ld/li; %f/g; %lf; %c; char *, %s
    Mathematik
        round()
    String
        strcpy(ziel, text);
*/