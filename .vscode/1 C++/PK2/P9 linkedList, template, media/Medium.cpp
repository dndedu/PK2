#include "medium.h"

// Statische Variable initialisieren
int Medium::naechsteId = 0; //

// Konstruktor
Medium::Medium(const std::string &titel, int jahr)
    : id(naechsteId++), titel(titel), jahr(jahr)
{
    // ID wird automatisch vergeben und hochgezählt [cite: 3]
}