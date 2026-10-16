#include <stdio.h>
#include <stdlib.h>

// FALSCH: Versucht einen Zeiger zu ändern, aber es funktioniert nicht
void allocate_wrong(int *ptr, int size)
{
    ptr = malloc(size * sizeof(int)); // Ändert nur die lokale Kopie!
    if (ptr != NULL)
    {
        ptr[0] = 42;
    }
}

// RICHTIG: Verwendet doppelte Zeiger um den ursprünglichen Zeiger zu ändern
void allocate_correct(int **ptr, int size)
{
    *ptr = malloc(size * sizeof(int)); // Ändert den ursprünglichen Zeiger!
    if (*ptr != NULL)
    {
        (*ptr)[0] = 42;
    }
}

// Beispiel: Linked List - Node am Anfang hinzufügen
struct Node
{
    int data;
    struct Node *next;
};

// FALSCH: head wird nicht geändert
void insert_wrong(struct Node *head, int value)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = head;
    head = new_node; // Ändert nur die lokale Kopie!
}

// RICHTIG: head wird tatsächlich geändert
void insert_correct(struct Node **head, int value)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node; // Ändert den ursprünglichen head-Zeiger!
}

void print_list(struct Node *head)
{
    printf("Liste: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    printf("=== Beispiel 1: Speicher allokieren ===\n");
    // Test der falschen Version
    int *array1 = NULL;
    printf("Vor allocate_wrong: array1 = %p\n", (void *)array1);
    allocate_wrong(array1, 5);
    printf("Nach allocate_wrong: array1 = %p\n", (void *)array1);
    if (array1 == NULL)
    {
        printf("FEHLER: array1 ist immer noch NULL!\n\n");
    }

    // Test der richtigen Version
    int *array2 = NULL;
    printf("Vor allocate_correct: array2 = %p\n", (void *)array2);
    allocate_correct(&array2, 5); // Übergebe Adresse von array2
    printf("Nach allocate_correct: array2 = %p\n", (void *)array2);
    if (array2 != NULL)
    {
        printf("SUCCESS: array2[0] = %d\n\n", array2[0]);
        free(array2);
    }

    printf("=== Beispiel 2: Linked List ===\n");
    // Test der falschen Insert-Funktion
    struct Node *list1 = NULL;
    printf("Vor insert_wrong:\n");
    print_list(list1);

    insert_wrong(list1, 10);
    insert_wrong(list1, 20);
    printf("Nach insert_wrong:\n");
    print_list(list1); // Liste bleibt leer!

    // Test der richtigen Insert-Funktion
    struct Node *list2 = NULL;
    printf("\nVor insert_correct:\n");
    print_list(list2);

    insert_correct(&list2, 10); // Übergebe Adresse von list2
    insert_correct(&list2, 20);
    printf("Nach insert_correct:\n");
    print_list(list2);

    // Aufräumen
    while (list2 != NULL)
    {
        struct Node *temp = list2;
        list2 = list2->next;
        free(temp);
    }

    return 0;
}