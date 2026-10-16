// C-Import
#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}

void printString(char string[])
{
    printf("%s\n", string);
}

void string_copy(char *duplikat, const char *original)
{
    // Alternative 1
    //  while (*duplikat++ = *original++)
    //      ;

    // Alternative 2
    for (int i = 0;; i++)
    {
        if (*(original + i) != '\0')
        {
            *(duplikat + i) = *(original + i);
        }
        else
        {
            *(duplikat + i) = '\0';
            break;
        }
    }
}

void print_mainArguments(int argc, const char *argv[])
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}

// C++
#include "utilities.h"

Utilities::Utilities()
{
    hlp_int = 0;
    hlp_double = 0.0;
}

void Utilities::setHlpInt(int i)
{
    hlp_int = i;
};

void Utilities::setHlpDouble(double d)
{
    hlp_double = d;
};