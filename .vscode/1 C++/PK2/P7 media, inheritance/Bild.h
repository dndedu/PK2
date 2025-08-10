#ifndef BILD_H
#define BILD_H

#include "Medium.h"

class Bild : public Medium
{
private:
    std::string ort;

public:
    // Konstruktor
    Bild(const std::string &titel, int jahr, const std::string &ort);

    // Getter-Funktion (inline)
    inline const std::string &getOrt() const { return ort; }

    // Überschriebene virtuelle Funktion
    void druckeDaten() const override;
};

#endif