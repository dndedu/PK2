#ifndef MEDIUM_H
#define MEDIUM_H

#include <string>

class Medium
{
protected:
    static int naechsteId; // Statische Variable für automatische ID-Vergabe
    int id;
    std::string titel;
    int jahr;

public:
    // Konstruktor
    Medium(const std::string &titel, int jahr);

    // Destruktor (virtuell für Polymorphie)
    virtual ~Medium() = default;

    // Getter-Funktionen (inline)
    inline int getId() const { return id; }
    inline const std::string &getTitel() const { return titel; }
    inline int getJahr() const { return jahr; }
    inline int getAlter() const { return 2021 - jahr; }

    // Virtuelle Funktion für polymorphe Ausgabe
    virtual void druckeDaten() const = 0;
};

#endif