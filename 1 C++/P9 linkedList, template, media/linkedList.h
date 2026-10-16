#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "iterator.h" // Include the templated iterator

namespace fhdo_pk2
{

    // Forward-Deklaration der templated Node-Struktur
    template <typename T>
    struct Node; // [cite: 32]

    template <typename T>
    class LinkedList
    {
    private:
        Node<T> *head; // [cite: 33]
        Node<T> *tail; // [cite: 34]
        int size;
        void clear(); // [cite: 34]

        // Innere Templated-Klasse ListIterator
        class ListIterator : public Iterator<T>
        {
        private:
            Node<T> *current; // [cite: 34]

        public:
            // Konstruktor
            ListIterator(Node<T> *start) : current(start) {} // [cite: 35]

            // Prüft ob noch weitere Elemente vorhanden sind [cite: 35]
            bool hasNext() override
            {
                return current != nullptr; // [cite: 45, 46]
            }

            // Liefert das nächste Element [cite: 36]
            T next() override
            {
                if (!current)
                    return nullptr;       // Return nullptr if no more elements, adjust if T is not a pointer
                T result = current->data; // [cite: 47]
                current = current->next;  // [cite: 47]
                return result;            // [cite: 47]
            }
        };

    public:
        // Erzeugt eine leere Liste. [cite: 109]
        LinkedList() : head(nullptr), tail(nullptr), size(0) {} // [cite: 48]

        // Kopier-Konstruktor [cite: 108]
        LinkedList(const LinkedList<T> &other); // [cite: 36, 37]

        // Kopierzuweisungsoperator [cite: 37]
        LinkedList<T> &operator=(const LinkedList<T> &other); // [cite: 37]

        // Destruktor [cite: 108]
        ~LinkedList(); // [cite: 37]

        // Fügt ein Element vom Typ T (in konstanter Zeit) an der letzten Listenposition hinzu. [cite: 113, 115]
        // Liefert den Wert 1, wenn das Element eingefügt werden konnte. Ansonsten wird der Wert 0 geliefert. [cite: 116, 118, 119]
        int append(T content); // [cite: 37]

        // Fügt ein Element vom Typ T an der Position p ein. Das erste Element der Liste befindet sich an der Position 0. [cite: 124, 126]
        // Das Element, das sich aktuell an der Position p befindet, wird nach rechts geschoben. [cite: 127, 128]
        // Falls sich weniger als p Elemente in der Liste befinden, wird der Text am Ende angefügt. [cite: 129]
        int insert(T content, int p); // [cite: 37, 130]

        // Löscht das Listenelement an der Position p. Das erste Element befindet sich an der Position 0. [cite: 131]
        // Falls das p-te Element nicht existiert, wird das letzte Element gelöscht. [cite: 132]
        // Die Anzahl der gelöschten Elemente wird als Funktionswert geliefert. [cite: 133]
        int remove(int p); // [cite: 37, 134]

        // Liefert das Element vom Typ T an der p-ten Listenpos. [cite: 135]
        // Das erste Listenelement befindet sich an der Position 0. [cite: 143]
        // Falls das p-te Element nicht existiert, wird nullptr geliefert. [cite: 144, 145]
        T get(int p); // [cite: 38, 146]

        // Liefert den Zugriff auf einen Iterator für die Liste. [cite: 110]
        Iterator<T> *iterator(); // [cite: 39]

        // Besucht alle Elemente der Liste und ruft für jedes Element die Funktion work auf. [cite: 147, 150]
        void visit_all(void (*work)(T t)); // [cite: 40, 158]

        // Returns the current size of the list
        int getSize() const
        {                // [cite: 40]
            return size; // [cite: 100, 101]
        }
    };

    // Templated Node-Struktur Definition
    template <typename T>
    struct Node
    {
        T data;        // Das Element vom Typ T
        Node<T> *next; // [cite: 42]

        // Konstruktor für Node
        Node(T d) : data(d), next(nullptr) {} // [cite: 42]

        // Destruktor für Node.
        // Für den Fall, dass T ein Zeigertyp ist, löscht der Node-Destruktor NICHT das Zielobjekt,
        // da die LinkedList die Ownership nicht übernimmt, es sei denn, dies ist explizit gewünscht.
        // Die Aufgabe verlangt die Implementierung für Zeigertypen und die manuelle Löschung im Hauptprogramm.
        ~Node()
        {
            // delete[] text; (entfernt von der alten Implementierung) [cite: 44, 45]
        }
    };

} // namespace fhdo_pk2

#endif // LINKEDLIST_H