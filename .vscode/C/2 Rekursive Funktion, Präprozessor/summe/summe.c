#include <stdio.h>

#define DEBUG 1
#define LOG(text) printf("Datei %s, Zeile %d: %s\n", __FILE__, __LINE__, text)

#define MIN(a, b) (a < b) ? a : b

int summe(int n)
{
  if (n == 0)
    return 0;
  return n + summe(n - 1);
}

int main()
{
#if DEBUG
  LOG("Vor Summe");
#endif
  printf("Summe = %d\n", summe(100));
  printf("Minimum = %d\n", MIN(100, 50));
}