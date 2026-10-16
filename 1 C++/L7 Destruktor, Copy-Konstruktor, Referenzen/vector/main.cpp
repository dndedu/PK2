#include <iostream>
#include "vector.h"

int main()
{
    Vector v{10};
    v.set(1, 200.0);

    std::cout << v.get(0) << std::endl;
    std::cout << v.get(1) << "\n"
              << std::endl;

    Vector w{v};
    w.set(0, 100.0);

    std::cout << w.get(0) << std::endl;
    std::cout << w.get(1) << "\n"
              << std::endl;

    return 0;
}