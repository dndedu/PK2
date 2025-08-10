#include "linkedList.h"
#include <cstring>

// Knoten-Struktur für die verkettete Liste
struct Node
{
    char *text; // Zeiger auf den gespeicherten Text
    Node *next; // Zeiger auf den nächsten Knoten

    // Konstruktor für einen neuen Knoten
    Node(const char *t) : next(nullptr)
    {
        if (t)
        {
            text = new char[strlen(t) + 1];
            strcpy(text, t);
        }
        else
        {
            text = nullptr;
        }
    }

    // Destruktor - gibt den Speicher für den Text frei
    ~Node()
    {
        delete[] text;
    }
};

// Konstruktor - erzeugt eine leere Liste
LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Copy-Konstruktor für die Initialisierung mit existierendem Objekt
LinkedList::LinkedList(const LinkedList &other) : head(nullptr), tail(nullptr), size(0)
{
    Node *current = other.head;
    while (current)
    {
        append(current->text);
        current = current->next;
    }
}

// Zuweisungsoperator
LinkedList &LinkedList::operator=(const LinkedList &other)
{
    if (this != &other)
    {
        // Aktuelle Liste löschen
        clear();

        // Elemente aus other kopieren
        Node *current = other.head;
        while (current)
        {
            append(current->text);
            current = current->next;
        }
    }
    return *this;
}

// Destruktor - gibt allen Speicher frei
LinkedList::~LinkedList()
{
    clear();
}

// Hilfsfunktion zum Löschen aller Elemente
void LinkedList::clear()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

// Fügt den Text am Ende der Liste hinzu (in konstanter Zeit)
int LinkedList::append(const char *text)
{
    if (!text)
        return 0;

    Node *newNode = new Node(text);
    if (!newNode || !newNode->text)
    {
        delete newNode;
        return 0;
    }

    if (!head)
    {
        // Liste ist leer
        head = tail = newNode;
    }
    else
    {
        // Neuen Knoten am Ende anhängen
        tail->next = newNode;
        tail = newNode;
    }

    size++;
    return 1;
}

// Fügt ein Element an Position p ein
int LinkedList::insert(const char *text, int p)
{
    if (!text)
        return 0;

    // Wenn Position >= Listenlänge, am Ende anhängen
    if (p >= size)
    {
        return append(text);
    }

    Node *newNode = new Node(text);
    if (!newNode || !newNode->text)
    {
        delete newNode;
        return 0;
    }

    // Am Anfang einfügen
    if (p <= 0)
    {
        newNode->next = head;
        head = newNode;
        if (!tail)
            tail = newNode;
        size++;
        return 1;
    }

    // An Position p einfügen
    Node *current = head;
    for (int i = 0; i < p - 1 && current; i++)
    {
        current = current->next;
    }

    if (current)
    {
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == nullptr)
        {
            tail = newNode;
        }
        size++;
        return 1;
    }

    delete newNode;
    return 0;
}

// Löscht das Element an Position p
int LinkedList::remove(int p)
{
    if (!head)
        return 0;

    // Wenn Position zu groß, letztes Element löschen
    if (p >= size - 1)
    {
        // Letztes Element finden und löschen
        if (size == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next != tail)
            {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        size--;
        return 1;
    }

    // Erstes Element löschen
    if (p <= 0)
    {
        Node *temp = head;
        head = head->next;
        if (!head)
            tail = nullptr;
        delete temp;
        size--;
        return 1;
    }

    // Element an Position p löschen
    Node *current = head;
    for (int i = 0; i < p - 1 && current->next; i++)
    {
        current = current->next;
    }

    if (current->next)
    {
        Node *temp = current->next;
        current->next = temp->next;
        if (temp == tail)
        {
            tail = current;
        }
        delete temp;
        size--;
        return 1;
    }

    return 0;
}

// Liefert den Text an Position p
const char *LinkedList::get(int p)
{
    if (p < 0 || p >= size || !head)
        return nullptr;

    Node *current = head;
    for (int i = 0; i < p && current; i++)
    {
        current = current->next;
    }

    return current ? current->text : nullptr;
}

// Berechnet den Index des ersten Elements mit dem gesuchten Text
int LinkedList::index_of(const char *text)
{
    if (!text || !head)
        return -1;

    Node *current = head;
    int index = 0;

    while (current)
    {
        if (strcmp(current->text, text) == 0)
        {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

// Liefert den Text des ersten Elements (in konstanter Zeit)
const char *LinkedList::first()
{
    return head ? head->text : nullptr;
}

// Liefert den Text des letzten Elements (in konstanter Zeit)
const char *LinkedList::last()
{
    return tail ? tail->text : nullptr;
}

// Besucht alle Elemente und ruft für jedes die Funktion work auf
void LinkedList::visit_all(void (*work)(const char *t))
{
    if (!work)
        return;

    Node *current = head;
    while (current)
    {
        work(current->text);
        current = current->next;
    }
}

// Hilfsfunktion für Tests - gibt die Größe zurück
int LinkedList::getSize() const
{
    return size;
}