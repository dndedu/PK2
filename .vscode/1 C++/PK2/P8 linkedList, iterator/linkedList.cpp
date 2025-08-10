#include "linkedList.h"
#include <cstring>

namespace fhdo_pk2
{
    // Node-Struktur Definition
    struct Node
    {
        char *text;
        Node *next;

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

        ~Node()
        {
            delete[] text;
        }
    };

    // ListIterator Implementierung
    LinkedList::ListIterator::ListIterator(Node *start) : current(start) {}

    bool LinkedList::ListIterator::hasNext()
    {
        return current != nullptr;
    }

    const char *LinkedList::ListIterator::next()
    {
        if (!current)
            return nullptr;
        const char *result = current->text;
        current = current->next;
        return result;
    }

    // LinkedList Implementierung
    LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    LinkedList::LinkedList(const LinkedList &other) : head(nullptr), tail(nullptr), size(0)
    {
        Node *current = other.head;
        while (current)
        {
            append(current->text);
            current = current->next;
        }
    }

    LinkedList &LinkedList::operator=(const LinkedList &other)
    {
        if (this != &other)
        {
            clear();
            Node *current = other.head;
            while (current)
            {
                append(current->text);
                current = current->next;
            }
        }
        return *this;
    }

    LinkedList::~LinkedList()
    {
        clear();
    }

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
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
        return 1;
    }

    int LinkedList::insert(const char *text, int p)
    {
        if (!text)
            return 0;

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

        if (p <= 0)
        {
            newNode->next = head;
            head = newNode;
            if (!tail)
                tail = newNode;
            size++;
            return 1;
        }

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

    int LinkedList::remove(int p)
    {
        if (!head)
            return 0;

        if (p >= size - 1)
        {
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

    const char *LinkedList::first()
    {
        return head ? head->text : nullptr;
    }

    const char *LinkedList::last()
    {
        return tail ? tail->text : nullptr;
    }

    Iterator *LinkedList::iterator()
    {
        return new ListIterator(head);
    }

    void LinkedList::visit_all(void (*work)(const char *t))
    {
        if (!work)
            return;

        Iterator *it = iterator();
        while (it->hasNext())
        {
            work(it->next());
        }
        delete it;
    }

    int LinkedList::getSize() const
    {
        return size;
    }

}