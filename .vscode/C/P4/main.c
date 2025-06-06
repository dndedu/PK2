#include <stdio.h>
#include <stdlib.h>

// Definition der Liste
typedef struct Liste
{
    int daten;
    struct Liste *next;
} Liste;

// Definition des Dictionarys
typedef struct Dictionary
{
    Liste **listen;
    int size;
} Dictionary;

// Funktion zum Erstellen eines neuen Dictionarys
Dictionary *erstelle_dictionary(int size)
{
    Dictionary *dict = malloc(sizeof(Dictionary));
    dict->size = size;
    dict->listen = malloc(size * sizeof(Liste *));
    for (int i = 0; i < size; i++)
    {
        dict->listen[i] = NULL;
    }
    return dict;
}

// Funktion zum Einfügen eines Elements in das Dictionary
int insert(Dictionary *dict, int daten)
{
    int hash_index = daten % dict->size;
    Liste *neue_liste = malloc(sizeof(Liste));
    neue_liste->daten = daten;
    neue_liste->next = dict->listen[hash_index];
    dict->listen[hash_index] = neue_liste;
    return 1;
}

// Funktion zum Überprüfen, ob ein Element im Dictionary vorhanden ist
int member(Dictionary *dict, int daten)
{
    int hash_index = daten % dict->size;
    Liste *aktuelle_liste = dict->listen[hash_index];
    while (aktuelle_liste != NULL)
    {
        if (aktuelle_liste->daten == daten)
        {
            return 1;
        }
        aktuelle_liste = aktuelle_liste->next;
    }
    return 0;
}

// Funktion zum Löschen eines Elements aus dem Dictionary
int delete(Dictionary *dict, int daten)
{
    int hash_index = daten % dict->size;
    Liste *vorherige_liste = NULL;
    Liste *aktuelle_liste = dict->listen[hash_index];
    while (aktuelle_liste != NULL)
    {
        if (aktuelle_liste->daten == daten)
        {
            if (vorherige_liste == NULL)
            {
                dict->listen[hash_index] = aktuelle_liste->next;
            }
            else
            {
                vorherige_liste->next = aktuelle_liste->next;
            }
            free(aktuelle_liste);
            return 1;
        }
        vorherige_liste = aktuelle_liste;
        aktuelle_liste = aktuelle_liste->next;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int size = 1;
    Dictionary *dict = erstelle_dictionary(size);

    for (int i = 1; i <= 2 * size; i++)
    {
        printf("%d", insert(dict, i));
    }
    for (int i = 1; i <= size; i++)
    {
        printf("%d", member(dict, i));
    }
    for (int i = size + 1; i <= 2 * size; i++)
    {
        printf("%d", delete(dict, i));
    }
    for (int i = 1; i <= 2 * size; i++)
    {
        printf("%d", member(dict, i));
    }
    printf("\n");

    // Alle Zahlen aus der Kommandozeile in das Dictionary aufnehmen
    for (int i = 1; i < argc; i++)
    {
        int daten = atoi(argv[i]);
        insert(dict, daten);
    }

    // Zahlen über die Tastatur einlesen und prüfen, ob sie im Dictionary vorhanden sind
    int daten;
    while (1)
    {
        printf("Geben Sie eine Zahl ein (-1 zum Beenden): ");
        scanf("%d", &daten);
        if (daten == -1)
        {
            break;
        }
        if (member(dict, daten))
        {
            printf("Die Zahl %d ist im Dictionary vorhanden.\n", daten);
        }
        else
        {
            printf("Die Zahl %d ist nicht im Dictionary vorhanden.\n", daten);
        }
    }

    return 0;
}