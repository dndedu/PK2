#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Forward-Deklaration der Node-Struktur
struct Node;

class LinkedList
{
private:
    Node *head; // Zeiger auf den ersten Knoten
    Node *tail; // Zeiger auf den letzten Knoten (für O(1) append)
    int size;   // Anzahl der Elemente in der Liste

    // Private Hilfsfunktion zum Löschen aller Elemente
    void clear();

public:
    // Konstruktor - erzeugt eine leere Liste
    LinkedList();

    // Copy-Konstruktor für die Initialisierung mit existierendem Objekt
    LinkedList(const LinkedList &other);

    // Zuweisungsoperator
    LinkedList &operator=(const LinkedList &other);

    // Destruktor - gibt allen Speicher frei
    ~LinkedList();

    // Fügt den Text am Ende der Liste hinzu (in konstanter Zeit)
    // Liefert 1 bei Erfolg, 0 bei Fehler
    int append(const char *text);

    // Fügt ein Element an Position p ein
    // Position 0 ist das erste Element
    // Falls p >= Listenlänge, wird am Ende angefügt
    // Liefert 1 bei Erfolg, 0 bei Fehler
    int insert(const char *text, int p);

    // Löscht das Element an Position p
    // Falls p >= Listenlänge, wird das letzte Element gelöscht
    // Liefert die Anzahl der gelöschten Elemente (0 oder 1)
    int remove(int p);

    // Liefert den Text an Position p
    // Liefert nullptr falls Position nicht existiert
    const char *get(int p);

    // Berechnet den Index des ersten Elements mit dem gesuchten Text
    // Liefert -1 falls nicht gefunden
    int index_of(const char *text);

    // Liefert den Text des ersten Elements (in konstanter Zeit)
    const char *first();

    // Liefert den Text des letzten Elements (in konstanter Zeit)
    const char *last();

    // Besucht alle Elemente und ruft für jedes die Funktion work auf
    void visit_all(void (*work)(const char *t));

    // Hilfsfunktion für Tests - gibt die Größe zurück
    int getSize() const;
};

#endif // LINKEDLIST_H