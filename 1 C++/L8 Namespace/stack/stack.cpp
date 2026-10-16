#include "stack.h"
#include <iostream>

pk2::stack::stack() : top{nullptr} {}

pk2::stack::stack(const stack &orig) : stack{}
{
    std::cout << "CopyConstructor" << std::endl;
    stack tmp;

    element *ptr = orig.top;
    while (ptr != nullptr)
    {
        tmp.push(ptr->key);
        ptr = ptr->next;
    }
    int k;
    while ((k = tmp.pop()) != -1)
    {
        this->push(k);
    }
}

pk2::stack::~stack()
{
    while (pop() != -1)
        ;
}

int pk2::stack::push(long k)
{
    element *neu = new element{k, top};
    if (neu != nullptr)
    {
        top = neu;
        return 1;
    }
    return 0;
}

long pk2::stack::pop()
{
    if (top != nullptr)
    {
        long k = top->key;
        element *temp = top;
        top = top->next;
        delete temp;
        return k;
    }
    return -1;
}