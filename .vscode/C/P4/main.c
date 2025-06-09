#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Struktur für die Listenelemente
typedef struct ListNode
{
    int key;
    struct ListNode *next;
} ListNode;

// Dictionary-Struktur
typedef struct
{
    ListNode *table[SIZE];
} Dictionary;

// Globales Dictionary
Dictionary dict;

// Hash-Funktion
int hash(int key)
{
    return key % SIZE;
}

// Initialisierung des Dictionaries
void init_dictionary()
{
    for (int i = 0; i < SIZE; i++)
    {
        dict.table[i] = NULL;
    }
}

// Insert-Operation (konstante Laufzeit)
int insert(int key)
{
    int index = hash(key);

    // Neuen Knoten erstellen
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    if (new_node == NULL)
    {
        // Nicht genügend Speicherplatz
        return 0;
    }

    // Neuen Knoten am Anfang der Liste einfügen
    new_node->key = key;
    new_node->next = dict.table[index];
    dict.table[index] = new_node;

    return 1;
}

// Member-Operation
int member(int key)
{
    int index = hash(key);
    ListNode *current = dict.table[index];

    // Liste durchsuchen
    while (current != NULL)
    {
        if (current->key == key)
        {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

// Delete-Operation
int delete(int key)
{
    int index = hash(key);
    ListNode *current = dict.table[index];
    ListNode *prev = NULL;

    // Liste durchsuchen
    while (current != NULL)
    {
        if (current->key == key)
        {
            // Element gefunden - löschen
            if (prev == NULL)
            {
                // Erstes Element in der Liste
                dict.table[index] = current->next;
            }
            else
            {
                // Element in der Mitte oder am Ende
                prev->next = current->next;
            }
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
    }

    return 0;
}

// Hilfsfunktion zur Ausgabe des Dictionary-Inhalts
void print_dictionary()
{
    printf("Dictionary contents:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("Bucket %d: ", i);
        ListNode *current = dict.table[i];
        while (current != NULL)
        {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
    printf("\n");
}

// Test-Funktion
void run_test()
{
    printf("=== Test-Sequenz ===\n");
    init_dictionary();

    int i;

    // Insert 1 bis 2*SIZE
    printf("Insert 1 bis %d: ", 2 * SIZE);
    for (i = 1; i <= 2 * SIZE; i++)
    {
        printf("%d", insert(i));
    }
    printf("\n");

    // Member 1 bis SIZE
    printf("Member 1 bis %d: ", SIZE);
    for (i = 1; i <= SIZE; i++)
    {
        printf("%d", member(i));
    }
    printf("\n");

    // Delete SIZE+1 bis 2*SIZE
    printf("Delete %d bis %d: ", SIZE + 1, 2 * SIZE);
    for (i = SIZE + 1; i <= 2 * SIZE; i++)
    {
        printf("%d", delete(i));
    }
    printf("\n");

    // Member 1 bis 2*SIZE
    printf("Member 1 bis %d: ", 2 * SIZE);
    for (i = 1; i <= 2 * SIZE; i++)
    {
        printf("%d", member(i));
    }
    printf("\n\n");
}

// Hauptprogramm mit Kommandozeilen-Argumenten
void run_interactive(int argc, char *argv[])
{
    printf("=== Interaktives Programm ===\n");
    init_dictionary();

    // Kommandozeilen-Argumente in Dictionary einfügen
    for (int i = 1; i < argc; i++)
    {
        int num = atoi(argv[i]);
        if (insert(num))
        {
            printf("Zahl %d eingefügt.\n", num);
        }
        else
        {
            printf("Fehler beim Einfügen von %d.\n", num);
        }
    }

    printf("\nDictionary nach Kommandozeilen-Eingabe:\n");
    print_dictionary();

    // Interaktive Eingabe
    printf("Geben Sie Zahlen ein (Ende mit -1):\n");
    int input;
    while (1)
    {
        printf("Zahl eingeben: ");
        if (scanf("%d", &input) != 1)
        {
            printf("Ungültige Eingabe!\n");
            continue;
        }

        if (input == -1)
        {
            printf("Programm beendet.\n");
            break;
        }

        if (member(input))
        {
            printf("Die Zahl %d ist im Dictionary enthalten.\n", input);
        }
        else
        {
            printf("Die Zahl %d ist NICHT im Dictionary enthalten.\n", input);
        }
    }
}

// Speicher freigeben
void cleanup()
{
    for (int i = 0; i < SIZE; i++)
    {
        ListNode *current = dict.table[i];
        while (current != NULL)
        {
            ListNode *temp = current;
            current = current->next;
            free(temp);
        }
        dict.table[i] = NULL;
    }
}

int main(int argc, char *argv[])
{
    printf("Hash Dictionary mit Chaining (SIZE = %d)\n", SIZE);
    printf("Hash-Funktion: h(a) = a mod %d\n\n", SIZE);

    // Test-Sequenz ausführen
    run_test();

    // Interaktives Programm
    run_interactive(argc, argv);

    // Speicher freigeben
    cleanup();

    return 0;
}