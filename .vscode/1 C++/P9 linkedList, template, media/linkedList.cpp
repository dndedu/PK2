#include "linkedList.h"
#include "Medium.h"
#include <cstring> // For strcmp in original, now not needed for generic T

namespace fhdo_pk2
{

    // --- LinkedList Implementation ---

    // Kopier-Konstruktor [cite: 48]
    template <typename T>
    LinkedList<T>::LinkedList(const LinkedList<T> &other) : head(nullptr), tail(nullptr), size(0)
    {
        Node<T> *current = other.head; // [cite: 48]
        while (current)
        {                            // [cite: 49]
            append(current->data);   // Fügt den Pointer hinzu
            current = current->next; // [cite: 50]
        }
    }

    // Kopierzuweisungsoperator [cite: 53]
    template <typename T>
    LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
    {
        if (this != &other)
        {
            clear();                       // Löscht die bestehenden Elemente [cite: 50]
            Node<T> *current = other.head; // [cite: 51]
            while (current)
            {                            // [cite: 51]
                append(current->data);   // Fügt den Pointer hinzu
                current = current->next; // [cite: 52]
            }
        }
        return *this; // [cite: 53]
    }

    // Destruktor [cite: 53]
    template <typename T>
    LinkedList<T>::~LinkedList()
    {
        clear(); // [cite: 54]
    }

    // Löscht alle Nodes in der Liste. Löscht NICHT die Zielobjekte der Pointer. [cite: 56]
    template <typename T>
    void LinkedList<T>::clear()
    {
        while (head)
        {                         // [cite: 54]
            Node<T> *temp = head; // [cite: 55]
            head = head->next;    // [cite: 55]
            delete temp;          // Löscht das Node-Objekt
        }
        tail = nullptr; // [cite: 55]
        size = 0;       // [cite: 56]
    }

    // Fügt ein Element am Ende der Liste hinzu [cite: 61]
    template <typename T>
    int LinkedList<T>::append(T content)
    {
        // Da wir es mit Zeigertypen zu tun haben, wird angenommen, dass 'content' ein gültiger Zeiger ist.
        Node<T> *newNode = new Node<T>(content); // [cite: 57]
        if (!newNode)
        { // [cite: 57]
            // delete newNode; (entfernt, da newNode nicht existiert, wenn new fehlschlägt) [cite: 58]
            return 0; // Speicherallokation fehlgeschlagen
        }

        if (!head)
        {                          // [cite: 58]
            head = tail = newNode; // [cite: 59]
        }
        else
        {
            tail->next = newNode; // [cite: 59]
            tail = newNode;       // [cite: 60]
        }

        size++;   // [cite: 60]
        return 1; // [cite: 61]
    }

    // Fügt ein Element an einer bestimmten Position ein [cite: 73]
    template <typename T>
    int LinkedList<T>::insert(T content, int p)
    {
        // Wenn die Position am oder über der aktuellen Größe liegt, wird angehängt. [cite: 62]
        if (p >= size)
        {                           // [cite: 62]
            return append(content); // [cite: 63]
        }

        Node<T> *newNode = new Node<T>(content); // [cite: 63]
        if (!newNode)
        { // [cite: 64]
            // delete newNode; (entfernt) [cite: 65]
            return 0; // Speicherallokation fehlgeschlagen
        }

        // Am Anfang einfügen [cite: 65]
        if (p <= 0)
        {                         // [cite: 65]
            newNode->next = head; // [cite: 66]
            head = newNode;       // [cite: 66]
            if (!tail)            // Wenn die Liste leer war [cite: 66]
                tail = newNode;   // [cite: 67]
            size++;               // [cite: 67]
            return 1;             // [cite: 67]
        }

        // In der Mitte einfügen [cite: 67]
        Node<T> *current = head; // [cite: 68]
        for (int i = 0; i < p - 1 && current; ++i)
        {                            // [cite: 68]
            current = current->next; // [cite: 69]
        }

        if (current)
        {                                  // [cite: 69]
            newNode->next = current->next; // [cite: 70]
            current->next = newNode;       // [cite: 70]
            if (newNode->next == nullptr)
            {                   // Wenn am Ende eingefügt [cite: 70]
                tail = newNode; // [cite: 71]
            }
            size++;   // [cite: 71]
            return 1; // [cite: 72]
        }

        delete newNode; // Sollte nicht passieren, wenn p gültig und kleiner als size ist [cite: 72]
        return 0;       // [cite: 73]
    }

    // Entfernt ein Element an einer bestimmten Position [cite: 87]
    template <typename T>
    int LinkedList<T>::remove(int p)
    {
        if (!head)    // [cite: 73]
            return 0; // Liste ist leer [cite: 74]

        // Behandlung des Entfernens des letzten Elements, wenn p außerhalb der Grenzen liegt (oder auf das letzte zeigt) [cite: 74]
        if (p >= size - 1)
        { // [cite: 74]
            if (size == 1)
            { // [cite: 74]
                // Wenn nur ein Element [cite: 74]
                delete head;           // [cite: 75]
                head = tail = nullptr; // [cite: 75]
            }
            else
            {
                // Letztes Element entfernen [cite: 75]
                Node<T> *current = head; // [cite: 76]
                while (current->next != tail)
                {                            // [cite: 76]
                    current = current->next; // [cite: 77]
                }
                delete tail;          // [cite: 78]
                tail = current;       // [cite: 78]
                tail->next = nullptr; // [cite: 78]
            }
            size--;   // [cite: 79]
            return 1; // [cite: 79]
        }

        // Behandlung des Entfernens des ersten Elements [cite: 79]
        if (p <= 0)
        {                         // [cite: 79]
            Node<T> *temp = head; // [cite: 80]
            head = head->next;    // [cite: 80]
            if (!head)            // Wenn die Liste leer wird [cite: 80]
                tail = nullptr;   // [cite: 81]
            delete temp;          // [cite: 81]
            size--;               // [cite: 81]
            return 1;             // [cite: 81]
        }

        // Element aus der Mitte entfernen [cite: 81]
        Node<T> *current = head; // [cite: 82]
        for (int i = 0; i < p - 1 && current->next; ++i)
        {                            // [cite: 82]
            current = current->next; // [cite: 83]
        }

        if (current && current->next)
        {                                  // Sicherstellen, dass current und der nächste Node existieren [cite: 83]
            Node<T> *temp = current->next; // [cite: 84]
            current->next = temp->next;    // [cite: 84]
            if (temp == tail)
            {                   // Wenn das entfernte Element der tail war [cite: 84]
                tail = current; // [cite: 85]
            }
            delete temp; // [cite: 85]
            size--;      // [cite: 85]
            return 1;    // [cite: 86]
        }

        return 0; // Element nicht gefunden oder ungültige Position [cite: 86]
    }

    // Liefert das Element an einer bestimmten Position [cite: 90]
    template <typename T>
    T LinkedList<T>::get(int p)
    {
        if (p < 0 || p >= size || !head) // [cite: 87]
            return nullptr;              // Gibt nullptr für außerhalb der Grenzen oder leere Liste zurück [cite: 88]

        Node<T> *current = head; // [cite: 88]
        for (int i = 0; i < p && current; ++i)
        {                            // [cite: 88]
            current = current->next; // [cite: 89]
        }
        return current ? current->data : nullptr; // [cite: 89, 90]
    }

    // Liefert einen neuen ListIterator für die Liste [cite: 97]
    template <typename T>
    Iterator<T> *LinkedList<T>::iterator()
    {
        return new ListIterator(head); // [cite: 97]
    }

    // Besucht alle Elemente und wendet die 'work'-Funktion an [cite: 100]
    template <typename T>
    void LinkedList<T>::visit_all(void (*work)(T t))
    {
        if (!work)  // [cite: 97]
            return; // Keine Funktion anzuwenden [cite: 98]

        Iterator<T> *it = iterator(); // [cite: 98]
        while (it->hasNext())
        {                     // [cite: 98]
            work(it->next()); // [cite: 99]
        }
        delete it; // Iterator aufräumen [cite: 99]
    }

    // Explizite Template-Instanziierung für Medium*, um die .cpp-Datei separat kompilieren zu können.
    // Dies ist entscheidend für die Trennung von Definition und Deklaration von Templates.
    template class LinkedList<Medium *>;
    template struct Node<Medium *>; // Node muss ebenfalls explizit instanziiert werden

} // namespace fhdo_pk2