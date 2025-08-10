#include <iostream>
#include "vector.h"

Vector::Vector(int size) : size{size}, feld{new double[size]} {}

Vector::Vector(const Vector &orig) : Vector{orig.size}
{
    for (int i = 0; i < orig.size; i++)
    {
        this->feld[i] = orig.feld[i];
    }
}

Vector::~Vector()
{
    std::cout << "Destruktor" << std::endl;
    delete[] feld;
}

void Vector::set(int index, double value)
{
    if ((index >= 0) && (index < size))
    {
        *(feld + index) = value;
    }
    else
    {
        // ToDo throw exception
        std::cout << "index out of range" << std::endl;
    }
}

double Vector::get(int index)
{
    if ((index >= 0) && (index < size))
    {
        return *(feld + index);
    }
    else
    {
        // ToDo throw exception
        std::cout << "index out of range" << std::endl;
        return -1;
    }
}