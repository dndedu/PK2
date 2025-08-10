#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100

// Große Datenstruktur simulieren
struct LargeData
{
    char buffer[1000];
    int numbers[100];
    double values[50];
};

// Methode 1: Daten komplett kopieren (LANGSAM)
void swap_by_copy(struct LargeData *a, struct LargeData *b)
{
    struct LargeData tmp = *a; // Kopiert ~2400 Bytes!
    *a = *b;                   // Kopiert ~2400 Bytes!
    *b = tmp;                  // Kopiert ~2400 Bytes!
}

// Methode 2: Nur Zeiger tauschen (SCHNELL)
void swap_pointers(struct LargeData **a, struct LargeData **b)
{
    struct LargeData *tmp = *a; // Nur 8 Bytes (64-bit)
    *a = *b;                    // Nur 8 Bytes
    *b = tmp;                   // Nur 8 Bytes
}

// Vergleichsfunktion für Zeiger-Array
int compare_data(struct LargeData *a, struct LargeData *b)
{
    return a->numbers[0] - b->numbers[0]; // Vergleiche erstes Element
}

// Bubble Sort mit Daten-Kopieren
void bubblesort_copy(struct LargeData arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j].numbers[0] > arr[j + 1].numbers[0])
            {
                swap_by_copy(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Bubble Sort mit Zeiger-Tauschen
void bubblesort_pointers(struct LargeData *arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (compare_data(arr[j], arr[j + 1]) > 0)
            {
                swap_pointers(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    // const int SIZE = 100;
    const int ITERATIONS = 1000;

    // Test-Daten erstellen
    struct LargeData data_array[SIZE];
    struct LargeData *pointer_array[SIZE];

    // Initialisierung
    for (int i = 0; i < SIZE; i++)
    {
        data_array[i].numbers[0] = SIZE - i; // Umgekehrte Reihenfolge
        pointer_array[i] = &data_array[i];
    }

    printf("Vergleich: Daten kopieren vs. Zeiger tauschen\n");
    printf("Array-Größe: %d Elemente\n", SIZE);
    printf("Größe pro Element: %zu Bytes\n\n", sizeof(struct LargeData));

    // Test 1: Daten kopieren
    clock_t start = clock();
    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        struct LargeData copy_array[SIZE];
        memcpy(copy_array, data_array, sizeof(data_array));
        bubblesort_copy(copy_array, SIZE);
    }
    clock_t end = clock();

    double time_copy = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Zeit mit Daten-Kopieren (%d Iterationen): %.6f Sekunden\n", ITERATIONS, time_copy);

    // Test 2: Zeiger tauschen
    start = clock();
    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        struct LargeData *ptr_copy[SIZE];
        memcpy(ptr_copy, pointer_array, sizeof(pointer_array));
        bubblesort_pointers(ptr_copy, SIZE);
    }
    end = clock();

    double time_pointers = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Zeit mit Zeiger-Tauschen (%d Iterationen): %.6f Sekunden\n", ITERATIONS, time_pointers);

    if (time_copy > 0)
    {
        printf("Speedup: %.2fx schneller\n", time_copy / time_pointers);
    }

    // Bytes-Vergleich pro Swap
    printf("\nBytes pro Swap-Operation:\n");
    printf("Daten kopieren: %zu Bytes\n", sizeof(struct LargeData) * 3);
    printf("Zeiger tauschen: %zu Bytes\n", sizeof(void *) * 3);

    return 0;
}