#include <iostream>
#include "stack.h"

int main()
{
    stack<long> s{-1};
    stack<double> d{-1.0};

    stack<long> *u = new stack<long>{-1};
    u->push(100);

    int i;
    for (i = 1; i <= 10; i++)
    {
        s.push(i);
    }

    /*
    for(i=0; i < 5; i++){
        std::cout << s.pop()  << std::endl;
    }
    */

    stack<long> t = s;
    std::cout << t.pop() << std::endl;
    std::cout << s.pop() << std::endl;

    return 0;
}