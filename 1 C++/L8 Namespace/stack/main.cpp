#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    pk2::stack s{};

    pk2::stack *u = new pk2::stack{};
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

    cout << "Before t = s" << endl;
    pk2::stack t = s;
    std::cout << t.pop() << std::endl;
    std::cout << s.pop() << std::endl;

    return 0;
}