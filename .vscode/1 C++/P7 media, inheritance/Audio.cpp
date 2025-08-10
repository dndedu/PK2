#include "Audio.h"
#include <iostream>

// Konstruktor
Audio::Audio(const std::string &titel, int jahr, const std::string &interpret, int spieldauer)
    : Medium(titel, jahr), interpret(interpret), spieldauer(spieldauer)
{
}

// Implementierung der virtuellen Funktion
void Audio::druckeDaten() const
{
    std::cout << "ID = " << id << " \"" << titel << "\" von "
              << interpret << " aus " << jahr << " Spieldauer: "
              << spieldauer << " sek." << std::endl;
}