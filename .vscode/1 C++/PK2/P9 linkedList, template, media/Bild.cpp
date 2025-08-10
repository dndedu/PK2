#include "bild.h"
#include <iostream>

// Konstruktor
Bild::Bild(const std::string &titel, int jahr, const std::string &ort)
    : Medium(titel, jahr), ort(ort)
{
}

// Implementierung der virtuellen Funktion
void Bild::druckeDaten() const
{
    std::cout << "ID = " << id << " \"" << titel << "\" aufgenommen im Jahr "
              << jahr << " in " << ort << std::endl; // [cite: 21]
}