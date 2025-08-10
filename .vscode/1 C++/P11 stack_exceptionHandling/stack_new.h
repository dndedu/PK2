#ifndef STACK_NEW_H
#define STACK_NEW_H

#include "stack_exception.h"

template <typename T>
class stack
{
private:
    // Element-Struktur für verkettete Liste
    struct element
    {
        T key;
        element *next;

        element(T key, element *next) : key{key}, next{next} {}
    };

    element *top; // Zeiger auf oberstes Element

public:
    // Konstruktoren und Destruktor
    stack();
    ~stack();
    stack(const stack &orig);

    // Stack-Operationen
    int push(T key);
    T pop(); // Wirft jetzt empty_stack_exception bei leerem Stack

    // Hilfsmethode zum Prüfen ob Stack leer ist
    bool is_empty() const;
};

// Konstruktor - initialisiert leeren Stack
template <typename T>
stack<T>::stack() : top{nullptr} {}

// Copy-Konstruktor
template <typename T>
stack<T>::stack(const stack &orig) : stack{}
{
    stack<T> tmp{};

    // Originalstack in temporären Stack kopieren
    element *ptr = orig.top;
    while (ptr != nullptr)
    {
        tmp.push(ptr->key);
        ptr = ptr->next;
    }

    // Aus temporärem Stack in this kopieren (kehrt Reihenfolge um)
    try
    {
        while (!tmp.is_empty())
        {
            this->push(tmp.pop());
        }
    }
    catch (const empty_stack_exception &)
    {
        // Sollte nicht auftreten, da wir is_empty() prüfen
    }
}

// Destruktor - alle Elemente löschen
template <typename T>
stack<T>::~stack()
{
    while (!is_empty())
    {
        try
        {
            pop();
        }
        catch (const empty_stack_exception &)
        {
            // Sollte nicht auftreten, da wir is_empty() prüfen
            break;
        }
    }
}

// Element auf Stack legen
template <typename T>
int stack<T>::push(T key)
{
    element *neu = new element{key, top};
    if (neu != nullptr)
    {
        top = neu;
        return 1; // Erfolg
    }
    return 0; // Fehler bei Speicherallokation
}

// Element vom Stack nehmen
template <typename T>
T stack<T>::pop()
{
    // Exception werfen wenn Stack leer ist
    if (top == nullptr)
    {
        throw empty_stack_exception("Versuch pop() auf leerem Stack auszuführen");
    }

    // Element entfernen und zurückgeben
    T k = top->key;
    element *temp = top;
    top = top->next;
    delete temp;
    return k;
}

// Prüft ob Stack leer ist
template <typename T>
bool stack<T>::is_empty() const
{
    return top == nullptr;
}

#endif