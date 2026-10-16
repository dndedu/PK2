#include <stdio.h>

int main()
{
    // Analysiere: int a, *b, **c, d[], *e[], ***f[];

    // 1. int a - normale Variable
    int a = 42;
    printf("a = %d\n", a);

    // 2. *b - Zeiger auf int
    int *b = &a;
    printf("*b = %d\n", *b);

    // 3. **c - Zeiger auf Zeiger auf int
    int **c = &b;
    printf("**c = %d\n", **c);

    // 4. d[] - Array von int (PROBLEM: Größe fehlt!)
    // int d[];  // FEHLER: "array has incomplete element type"
    int d[5] = {1, 2, 3, 4, 5}; // Korrekt
    printf("d[0] = %d\n", d[0]);

    // 5. *e[] - Array von Zeigern auf int (PROBLEM: Größe fehlt!)
    // int *e[];  // FEHLER: "array has incomplete element type"
    int *e[3] = {&a, &d[1], &d[2]}; // Korrekt
    printf("*e[0] = %d\n", *e[0]);

    // 6. ***f[] - Array von Zeigern auf Zeiger auf Zeiger auf int (PROBLEM!)
    // int ***f[];  // FEHLER: Größe fehlt UND sehr komplex
    int ***f[2]; // Deklaration möglich, aber...
    f[0] = &c;   // f[0] zeigt auf c (welches auf b zeigt, welches auf a zeigt)
    printf("***f[0] = %d\n", ***f[0]);

    printf("\n=== Detaillierte Analyse ===\n");
    // Zeige Speicher-Layout
    printf("Adressen:\n");
    printf("&a = %p\n", (void *)&a);
    printf("b = %p (zeigt auf a)\n", (void *)b);
    printf("&b = %p\n", (void *)&b);
    printf("c = %p (zeigt auf b)\n", (void *)c);
    printf("&c = %p\n", (void *)&c);
    printf("f[0] = %p (zeigt auf c)\n", (void *)f[0]);

    printf("\nDereferenzierung:\n");
    printf("a = %d\n", a);
    printf("*b = %d (über b)\n", *b);
    printf("**c = %d (über c)\n", **c);
    printf("***f[0] = %d (über f[0])\n", ***f[0]);

    return 0;
}