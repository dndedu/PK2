#include <stdio.h>
#include <string.h>
// Option 1
int laenge(char text[])
{
    int i = 0;
    while (text[i] != '\0')
    {
        i++;
    }
    return i;
}

// // Option 2
// int laenge(char text[])
// {
//   int c = 0;
//   while (text[c])
//   {
//     c++;
//   }
//   return c;
// }

int main()
{
    char text[100];
    strcpy(text, "Hallo");
    printf("Länge = %d\n", laenge(text));
    return 0;
}