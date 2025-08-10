#include <stdio.h>

long summe(int n)
{
  if (n == 0)
    return 0;
  return n + summe(n - 1); // Rekursion
}

/*
// schlechte Loesung
void quadrat(int x){
  printf("%d\n", x*x);
}
*/

// gute Loesung
int quadrat(int x)
{
  return x * x;
}

void print_quadrat(int x)
{
  printf("%d\n", quadrat(x));
}

int main()
{
  print_quadrat(2);
  int a = 2 * quadrat(2);

  printf("Summe(%d) = %ld\n", a, summe(a));
  return 0;
}