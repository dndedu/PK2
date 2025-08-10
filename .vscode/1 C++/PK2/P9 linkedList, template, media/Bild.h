#ifndef BILD_H
#define BILD_H

#include "medium.h"

class Bild : public Medium
{
private:
    std::string ort; // [cite: 17]
public:
    // Konstruktor
    Bild(const std::string &titel, int jahr, const std::string &ort); // [cite: 18]
    // Getter-Funktion (inline)
    inline const std::string &getOrt() const { return ort; } // [cite: 18, 19]

    // Überschriebene virtuelle Funktion
    void druckeDaten() const override; // [cite: 19, 20]
};
#endif