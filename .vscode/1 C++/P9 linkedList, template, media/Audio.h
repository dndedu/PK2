#ifndef AUDIO_H
#define AUDIO_H

#include "medium.h"

class Audio : public Medium
{
private:
    std::string interpret; // [cite: 11]
    int spieldauer;        // in Sekunden [cite: 11]

public:
    // Konstruktor
    Audio(const std::string &titel, int jahr, const std::string &interpret, int spieldauer); // [cite: 12]
    // Getter-Funktionen (inline)
    inline const std::string &getInterpret() const { return interpret; } // [cite: 12, 13]
    inline int getSpieldauer() const { return spieldauer; }              // [cite: 13, 14]

    // Überschriebene virtuelle Funktion
    void druckeDaten() const override; // [cite: 14, 15]
};
#endif