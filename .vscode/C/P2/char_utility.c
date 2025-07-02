#include <stdio.h>

char to_upper_case(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 32;
    }
    return c;
}

void upper(char text[])
{
    int pos = 0;
    while (text[pos])
    {
        text[pos] = to_upper_case(text[pos]);
        pos++;
    }
}