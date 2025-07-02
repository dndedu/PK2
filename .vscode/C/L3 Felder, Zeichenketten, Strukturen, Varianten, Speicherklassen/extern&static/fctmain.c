#include <stdio.h>

extern long counter;
void print_counter();

int quadrat(int x)
{
    counter++;
    return x * x;
}

int summe(int n)
{
    static int c = 0;
    c++;
    printf("Anzahl Aufrufe summe = %d\n", c);

    // // vorige Lösung
    // if (n == 0)
    //     return 0;

    // ein Aufruf weniger
    if (n == 1)
        return 1;
    return n + summe(n - 1);
}

int main()
{
    printf("Quadrat %d\n", quadrat(10));
    print_counter();
    printf("Summe = %d\n", summe(10));
    return 0;
}