#include <stdio.h>

// 1. Definiere typsichere Funktionen
static inline int min_int(int a, int b) { return (a < b) ? a : b; }
static inline float min_float(float a, float b) { return (a < b) ? a : b; }

// 2. Die Generische "Weiche"
// Je nachdem, welchen Typ 'a' hat, wird die passende Funktion gewählt.
#define MIN(a, b) _Generic((a), \
    int: min_int,               \
    float: min_float,           \
    default: min_int            \
)(a, b)

int main() {
    int x = 2;
    int y = 3;

    // Da min_int aufgerufen wird, wird x++ garantiert nur 1x ausgewertet
    int result = MIN(x++, y);

    printf("C11 Ergebnis: %d\n", result);
    printf("x nachher: %d\n", x);

    // Funktioniert jetzt auch sauber mit Floats!
    float f = 5.5f;
    printf("Float-Min: %.1f\n", MIN(f, 4.2f));

    return 0;
}

//Execute with
//gcc -std=c11 -Wall test_C11.c -o test_C11