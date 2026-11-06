/*
 * Bonusaufgabe Speicherverwaltung C (Programmierkurs 2)
 * Eigene Speicherverwaltung auf Basis eines globalen char-Arrays.
 *
 * Übersetzen: gcc -Wall -o speicherverwaltung speicherverwaltung.c
 */
#include <stdio.h>
#include <string.h> /* memcpy, strlen (laut Aufgabe erlaubt) */

#define MEMSIZE 80 /* Größe des simulierten Speichers in Byte */

/* ------------------------------------------------------------------
 * 1. Speicher
 * Globale Variablen liegen im statischen Speicherbereich und werden
 * automatisch mit 0 initialisiert. Dadurch ist beim Programmstart
 * der komplette Speicher "frei" (Flag 0) und alle Bytes sind 0.
 * ------------------------------------------------------------------ */
static char memory[MEMSIZE]; /* die eigentlichen Daten            */
static char belegt[MEMSIZE]; /* Flag je Byte: 1 = belegt, 0 = frei */

/* ------------------------------------------------------------------
 * 2. Zeiger-Struktur
 * Ein Zeiger besteht aus Startadresse (Index im Array memory) und
 * der Größe der verwiesenen Daten in Byte.
 * Ungültiger Zeiger ("null pointer"): adresse = -1.
 * ------------------------------------------------------------------ */
typedef struct
{
    int adresse; /* Index des ersten Bytes in memory, -1 = ungültig */
    int groesse; /* Anzahl der Bytes                                */
} pointer_t;

#define NULL_ADRESSE (-1)

/* Hilfsfunktion: Prüft, ob ein Zeiger ein "null pointer" ist */
int ptrisnull(pointer_t p)
{
    return p.adresse == NULL_ADRESSE;
}

/* ------------------------------------------------------------------
 * 3. Zeiger-Operationen
 * ------------------------------------------------------------------ */

/* Liefert einen void-Zeiger auf die von p verwiesenen Daten
   (Adresse des Arrayelements memory[p.adresse]). */
void *ptrget(pointer_t p)
{
    if (ptrisnull(p))
        return NULL; /* ungültiger Zeiger */
    return &memory[p.adresse];
}

/* Kopiert p.groesse Bytes von v in den Speicher ab p.adresse. */
void ptrset(pointer_t p, const void *v)
{
    if (ptrisnull(p))
        return; /* ungültiger Zeiger */
    memcpy(&memory[p.adresse], v, p.groesse);
}

/* ------------------------------------------------------------------
 * 4. Speicherverwaltung
 * ------------------------------------------------------------------ */

/* Reserviert n Byte nach dem "First-Fit"-Prinzip: Der erste freie
   Bereich, der mindestens n zusammenhängende Bytes umfasst, wird
   genommen. Ist keiner vorhanden, wird ein null pointer geliefert. */
pointer_t memalloc(int n)
{
    pointer_t p = {NULL_ADRESSE, 0}; /* Vorbelegung: null pointer */
    int i, j;
    int frei = 0; /* Länge des aktuellen freien Bereichs */

    if (n <= 0)
        return p; /* sinnlose Anforderung */

    for (i = 0; i < MEMSIZE; i++)
    {
        if (belegt[i] == 0)
            frei++; /* freies Byte: Bereich wächst */
        else
            frei = 0; /* belegtes Byte: von vorn zählen */

        if (frei == n)
        {                          /* passender Bereich gefunden */
            p.adresse = i - n + 1; /* Startindex des Bereichs */
            p.groesse = n;
            for (j = p.adresse; j < p.adresse + n; j++)
                belegt[j] = 1; /* Bereich als belegt markieren */
            return p;
        }
    }
    return p; /* nicht genug Speicher: null pointer */
}

/* Gibt den Bereich von p wieder frei. Es wird nur das Flag
   zurückgesetzt; die Bytes behalten ihren Inhalt (siehe Beispielausgabe). */
void memfree(pointer_t p)
{
    int i;
    if (ptrisnull(p))
        return;
    for (i = p.adresse; i < p.adresse + p.groesse; i++)
        belegt[i] = 0;
}

/* ------------------------------------------------------------------
 * 5. Speicherausgabe
 * Format je Byte: [<Adresse (3 Stellen)>:<Hex (2 Stellen)>:<Flag>]
 * c = Anzahl der Spalten je Zeile.
 * ------------------------------------------------------------------ */
void memdump(int c)
{
    static int aufrufe = 0; /* zählt die Dumps (für die Überschrift) */
    int i;

    aufrufe++;
    printf("=== MEMDUMP %d ===\n", aufrufe);

    for (i = 0; i < MEMSIZE; i++)
    {
        /* (unsigned char): verhindert Vorzeichenerweiterung bei Hex-Ausgabe */
        printf("[%03d:%02X:%c]", i, (unsigned char)memory[i],
               belegt[i] ? '#' : '_');
        if ((i + 1) % c == 0) /* Zeilenumbruch nach c Spalten */
            printf("\n");
    }
    if (MEMSIZE % c != 0) /* letzte Zeile abschließen */
        printf("\n");
}

/* ------------------------------------------------------------------
 * Testprogramm
 * nr = Anzahl bisheriger Testaufrufe. Rückgabe: 1 = Erfolg, 0 = Fehler
 * ------------------------------------------------------------------ */
char test(int nr)
{
    pointer_t pInt, pText, pDouble;
    int zahl = 271; /* Zwischenspeicher für ptrset */
    double werte[3] = {0.1, 2.3, -4.5};
    double gelesen[3];

    printf("##### TESTAUFRUF %d #####\n", nr);

    memdump(8); /* 1. leerer Speicher */

    pInt = memalloc(sizeof(int)); /* 2. Speicher für einen int */
    if (ptrisnull(pInt))
        return 0;        /* 3. null-Prüfung */
    ptrset(pInt, &zahl); /* 4. 271 schreiben */
    memdump(8);          /* 5. */

    pText = memalloc(strlen("Hello World") + 1); /* 6. +1 für das '\0' */
    if (ptrisnull(pText))
        return 0;                 /* 7. */
    ptrset(pText, "Hello World"); /* 8. */
    memdump(8);                   /* 9. */

    memfree(pInt); /* 10. int freigeben */
    memdump(8);    /* 11. */

    pDouble = memalloc(3 * sizeof(double)); /* 12. Platz für 3 double */
    if (ptrisnull(pDouble))
        return 0;           /* 13. */
    ptrset(pDouble, werte); /* 14. Array schreiben */
    memdump(8);             /* 15. */

    /* 16. Zeichenkette lesend über den Zeiger ausgeben */
    printf("Text: %s\n", (char *)ptrget(pText));

    /* 17. Double-Array lesend ausgeben. Zuerst in ein lokales Array
       kopieren: Die Adresse im char-Array ist nicht zwingend passend
       für double ausgerichtet (Alignment). */
    memcpy(gelesen, ptrget(pDouble), sizeof(gelesen));
    printf("Wert[1]: %.1f\n", gelesen[1]);

    return 1; /* 18. */
}

int main(void)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (!test(i))
            fprintf(stderr, "Fehler: Testaufruf %d - nicht genug Speicher!\n", i);
    }
    return 0;
}