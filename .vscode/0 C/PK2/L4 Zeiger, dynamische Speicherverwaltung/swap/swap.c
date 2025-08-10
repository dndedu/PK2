#include <stdio.h>

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    int a = 100;
    int b = 200;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}