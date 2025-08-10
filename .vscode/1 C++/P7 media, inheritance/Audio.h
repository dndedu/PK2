#ifndef AUDIO_H
#define AUDIO_H

#include "Medium.h"

class Audio : public Medium
{
private:
    std::string interpret;
    int spieldauer; // in Sekunden

public:
    // Konstruktor
    Audio(const std::string &titel, int jahr, const std::string &interpret, int spieldauer);

    // Getter-Funktionen (inline)
    inline const std::string &getInterpret() const { return interpret; }
    inline int getSpieldauer() const { return spieldauer; }

    // Überschriebene virtuelle Funktion
    void druckeDaten() const override;
};

#endif