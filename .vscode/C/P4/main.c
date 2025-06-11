#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct listNode
{
    int key;
    struct listNode *next;
} listNode;

typedef struct dictionary
{
    listNode *table[SIZE];
} dictionary;

dictionary dict;

int hash(int key)
{
    return key % SIZE;
}

void init_dictionary()
{
    for (int i = 0; i < SIZE; i++)
    {
        dict.table[i] = NULL;
    }
}

// Insert-Funktion mit konstanter Laufzeit
int insert(int key)
{
    int index = hash(key);

    // Neuen Knoten erstellen
    listNode *new_node = (listNode *)malloc(sizeof(listNode));
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

// Funktion, welche überprüft, ob Wert im dictionary vorhanden ist
int member(int key)
{
    int index = hash(key);
    listNode *current = dict.table[index];

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

// Funktion für das Löschen eines Listenelementes
int delete(int key)
{
    int index = hash(key);
    listNode *current = dict.table[index];
    listNode *prev = NULL;

    while (current != NULL)
    {
        if (current->key == key)
        {
            // Element gefunden, löschen
            if (prev == NULL)
            {
                // Erstes Element in der Liste
                dict.table[index] = current->next;
            }
            else
            {
                // Element in der Mitte / am Ende
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

void print_dictionary()
{
    printf("dictionary contents:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("Bucket %d: ", i);
        listNode *current = dict.table[i];
        while (current != NULL)
        {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
    printf("\n");
}

// Funktion für vorgegebenen Test des Programms
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

    print_dictionary();

    // Member-Prüfung 1 bis SIZE
    printf("Member 1 bis %d: ", SIZE);
    for (i = 1; i <= SIZE; i++)
    {
        printf("%d", member(i));
    }
    printf("\n");

    // Löschen von Listenelementen von SIZE+1 bis 2*SIZE
    printf("Delete %d bis %d: ", SIZE + 1, 2 * SIZE);
    for (i = SIZE + 1; i <= 2 * SIZE; i++)
    {
        printf("%d", delete(i));
    }
    printf("\n");

    print_dictionary();

    // Member-Prüfung 1 bis 2*SIZE
    printf("Member 1 bis %d: ", 2 * SIZE);
    for (i = 1; i <= 2 * SIZE; i++)
    {
        printf("%d", member(i));
    }
    printf("\n\n");
}

// Funktion mit Kommandozeilen-Argumenten
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
            // Puffer leeren, beispielsweise bei Eingabe von NULL, welche Schleife auslöst
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            continue;
        }

        if (input == -1)
        {
            printf("Programm beendet.\n");
            break;
        }

        if (member(input))
        {
            printf("Die Zahl %d ist im dictionary enthalten.\n", input);
        }
        else
        {
            printf("Die Zahl %d ist NICHT im dictionary enthalten.\n", input);
        }
    }
}

// Speicher freigeben
void cleanup()
{
    for (int i = 0; i < SIZE; i++)
    {
        listNode *current = dict.table[i];
        while (current != NULL)
        {
            listNode *temp = current;
            current = current->next;
            free(temp);
        }
        dict.table[i] = NULL;
    }
}

int main(int argc, char *argv[])
{
    printf("Hash dictionary mit Chaining (SIZE = %d)\n", SIZE);
    printf("Hash-Funktion: h(a) = a mod %d\n\n", SIZE);

    // Test-Sequenz ausführen
    run_test();

    // Interaktives Programm
    run_interactive(argc, argv);

    // Speicher freigeben
    cleanup();

    return 0;
}