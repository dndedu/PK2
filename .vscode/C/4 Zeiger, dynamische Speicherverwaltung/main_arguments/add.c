#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error");
    }
    else
    {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        int summe = a + b;
        printf("%d + %d = %d\n", a, b, summe);
    }
    return 0;
}