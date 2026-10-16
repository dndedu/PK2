#include <iostream>
#include "simple.h"

Simple::Simple(int nr) : number(nr)
{
}

Simple::~Simple()
{
    std::cout << "Objekt " << number
              << std::endl;
}