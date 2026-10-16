#include "stack.h"
#include <iostream>

int main()
{
    Stack s;

    s.push(10);
    s.push(100);

    Stack p{s}; // without proper copy constructor: shallow copy, points to same memory as s.top
    p.push(1);  // p->1->100->10; s->100->10

    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << p.pop() << std::endl;
    return 0;
}