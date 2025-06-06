#include <stdio.h>
#include <math.h>

void dualzahl(int x)
{
    if (x < 0 || x > 65535)
    {
        printf("Parameter ausserhalb des gültigen Bereichs!\n");
        return;
    }

    int i;
    for (i = 15; i >= 0; i--)
    {
        int bit = (x / (int)pow(2, i));
        if (bit == 1)
        {
            x -= (int)pow(2, i);
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}

int main()
{
    int read;
    scanf("%d", &read);
    dualzahl(read); // Beispielaufruf
    return 0;
}