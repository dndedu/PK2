#include <stdio.h>  // printf()
#include <stdlib.h> // malloc()
#include <string.h> // strcat()

#include "task1_count_space_in_string.h"
#include "task2_minimum_in_array.h"
#include "task3_string_concatenation.h"
#include "task4_factorial_binomial.h"

int main()
{
    printf("1. Leerzeichen zählen:\n");
    char test_string[] = "Hallo Welt! Dies ist ein Test.";
    printf("String: \"%s\"\n", test_string);
    printf("Leerzeichen (Index): %d\n", count_space_withIndex(test_string));
    printf("Leerzeichen (Pointer): %d\n\n", count_space_withPointer(test_string));

    printf("2. Minimum finden:\n");
    double numbers[] = {3.14, 2.71, 1.41, 0.57, 4.67};
    int count = sizeof(numbers) / sizeof(numbers[0]);
    printf("Array: ");
    for (int i = 0; i < count; i++)
    {
        printf("%.2f ", numbers[i]);
    }
    printf("\nMinimum: %.2f\n\n", min(numbers, count));

    printf("3. String-Konkatenation:\n");
    char *str1 = "Hallo ";
    char *str2 = "Welt!";
    char *concatenated = stringcat(str1, str2);
    if (concatenated != NULL)
    {
        printf("\"%s\" + \"%s\" = \"%s\"\n", str1, str2, concatenated);
        free(concatenated); // aufgrund von malloc() in stringcat
    }
    printf("\n");

    printf("4. Fakultät und Binomialkoeffizient:\n");
    printf("\nFakultäten:\n");
    for (int i = 0; i <= 10; i++)
    {
        printf("%d! = %lu\n", i, fakultaet(i));
    }
    printf("\nBinomialkoeffizient:\n");
    printf("C(10,0) = %lu\n", binomialkoeffizient(10, 0));
    printf("C(10,1) = %lu\n", binomialkoeffizient(10, 1));
    printf("C(10,10) = %lu\n", binomialkoeffizient(10, 10));
    printf("C(49,6) = %lu\n", binomialkoeffizient(49, 6));

    return 0;
}