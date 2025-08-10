#include "student.h"
#include <iostream>
#include <string>

// Konstruktor
Student::Student()
{
    name = "name_placeholder";
    matrikelnummer = -1;
}

Student::Student(const char *n, int m) : Student()
{
    name = n;
    matrikelnummer = m;
}

// Getter
int Student::getMatrikelnr()
{
    return matrikelnummer;
}

const char *Student::getName()
{
    return name;
}

// Methoden
void Student::druckeDaten()
{
    std::cout << "Name: " << name << std::endl
              << "Matrikelnummer: " << matrikelnummer;
}