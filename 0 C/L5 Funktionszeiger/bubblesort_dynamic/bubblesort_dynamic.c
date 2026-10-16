#include <stdio.h>

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int comparelth(int a, int b)
{
  if (a > b)
    return 1;
  else if (a < b)
    return -1;
  return 0;
}

int comparehtl(int a, int b)
{
  return -1 * comparelth(a, b);
}

void bubblesort(int feld[], int length,
                int (*compare)(int a, int b))
{
  int sorted = 1;
  int i, j;
  for (i = 0; i < length; i++)
  {
    sorted = 1;
    for (j = 0; j < length - i - 1; j++)
    {
      if ((*compare)(feld[j], feld[j + 1]) > 0)
      {
        swap(&feld[j], &feld[j + 1]);
        sorted = 0;
      }
    }
    if (sorted)
      break;
  }
}

int main()
{
  int a[] = {9, 2, 3, 4, 5, 6, 7, 8, 1};
  bubblesort(a, 9, &comparelth);
  // bubblesort(a, 9, &comparehtl);

  int i;
  for (i = 0; i < 9; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}