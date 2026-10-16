#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Zurückgegebener neuer String muss mit free() freigegeben werden
char *stringcat(const char *str1, const char *str2)
{
    if (str1 == NULL || str2 == NULL)
    {
        return NULL;
    }

    int length_string1 = strlen(str1); // https://cplusplus.com/reference/cstring/strlen/ ; excluding terminating null character
    int length_string2 = strlen(str2);

    char *result = malloc(length_string1 + length_string2 + 1); //+1 für Nullterminator
    if (result == NULL)
    {
        return NULL;
    }

    strcpy(result, str1); // https://cplusplus.com/reference/cstring/strcpy/ ; including terminating null character
    strcat(result, str2); // https://cplusplus.com/reference/cstring/strcat/ ; terminating null character overwritten by first character of source, new one included at end of new string

    return result;
}