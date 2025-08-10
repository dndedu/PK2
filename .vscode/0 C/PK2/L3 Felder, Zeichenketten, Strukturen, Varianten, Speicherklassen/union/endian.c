#include <stdio.h>

union endian
{
    int i;
    unsigned char byte[sizeof(int)];
};

int main()
{
    union endian e;
    e.i = 256;

    int i;
    for (i = 0; i < sizeof(int); i++)
    {
        printf("%d", e.byte[i]);
    }
    printf("\n");

    return 0;
}