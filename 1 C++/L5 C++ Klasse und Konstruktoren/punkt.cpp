#include "punkt.h"
#include <iostream>

Punkt::Punkt(){
    x = 0;
    y = 0;
}

Punkt::Punkt(int x, int y) : x {x}, y {y}{ 
}

int Punkt::getX(){
    return x;
}

int Punkt::getY(){
    return y;
}

std::string Punkt::to_string(){
    return std::string("(") + std::to_string(x) + 
           std::string(", ") + std::to_string(y) + std::string(")");
}