#include "punkt.h"
#include <iostream>

void print(Punkt p)
{
    std::cout << p.to_string() << std::endl;
}

int main()
{

    /* Punkt s{100, 500};
    Punkt *p = new Punkt{900, 1000};

    std::cout << s.getX() << std::endl;
    std::cout << p->getX() << std::endl;

    delete p; */

    std::cout << 1 << std::endl;
    Punkt p{200, 500};
    std::cout << 2 << std::endl;
    Punkt s{p};
    std::cout << 3 << std::endl;
    print(s);
    std::cout << 4 << std::endl;
    std::cout << p.to_string() << std::endl;
    std::cout << 5 << std::endl;

    // Punkt p[100];
    return 0;
}