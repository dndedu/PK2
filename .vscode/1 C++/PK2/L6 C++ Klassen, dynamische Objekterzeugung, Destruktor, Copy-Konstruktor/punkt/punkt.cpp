#include "punkt.h"
#include <iostream>

Punkt::Punkt()
{
    x = 0;
    y = 0;
}

Punkt::Punkt(int x, int y) : x{x}, y{y}
{
}

// Wird hier nicht benoetigt. Dient nur der Veranschaulichung
Punkt::~Punkt()
{
    std::cout << "Destruktor" << std::endl;
}

// Wird hier nicht benoetigt. Dient nur der Veranschaulichung
Punkt::Punkt(const Punkt &orig) : x{orig.x}, y{orig.y}
{
    std::cout << "Copy-Konstruktor" << std::endl;
}

int Punkt::getX()
{
    return x;
}

int Punkt::getY()
{
    return y;
}

std::string Punkt::to_string()
{
    return std::string("(") + std::to_string(x) +
           std::string(", ") + std::to_string(y) + std::string(")");
}