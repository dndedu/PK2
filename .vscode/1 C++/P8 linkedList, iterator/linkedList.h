#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "iterator.h"

namespace fhdo_pk2
{
    // Forward-Deklaration der Node-Struktur
    struct Node;

    class LinkedList
    {
    private:
        Node *head;
        Node *tail;
        int size;
        void clear();

        // Innere Klasse ListIterator
        class ListIterator : public Iterator
        {
        private:
            Node *current;

        public:
            ListIterator(Node *start);
            bool hasNext() override;
            const char *next() override;
        };

    public:
        LinkedList();
        LinkedList(const LinkedList &other);
        LinkedList &operator=(const LinkedList &other);
        ~LinkedList();

        int append(const char *text);
        int insert(const char *text, int p);
        int remove(int p);
        const char *get(int p);
        int index_of(const char *text);
        const char *first();
        const char *last();

        // Iterator-Methode
        Iterator *iterator();

        // visit_all mit Iterator-Implementierung
        void visit_all(void (*work)(const char *t));

        int getSize() const;
    };
}

#endif // LINKEDLIST_H