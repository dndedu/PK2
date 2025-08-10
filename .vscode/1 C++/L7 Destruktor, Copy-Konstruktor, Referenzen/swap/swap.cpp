#include <stdio.h>

// // pointers, C and C++
// void swap(int *a, int *b){
//   int tmp = *a;
//   *a = *b;
//   *b = tmp;
// }

// referencing, C++
void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

int main()
{
  int x = 100;
  int y = 200;

  printf("before swap: x = %d, y = %d\n", x, y);
  // swap(&x, &y);
  swap(x, y);
  printf("after swap: x = %d, y = %d\n", x, y);

  return 0;
}