#ifndef MEDIUM_H
#define MEDIUM_H

#include <string>

class Medium
{
protected:
    static int naechsteId; // Statische Variable für automatische ID-Vergabe
    int id;                // [cite: 2]
    std::string titel;     // [cite: 2]
    int jahr;              // [cite: 2]
public:
    // Konstruktor
    Medium(const std::string &titel, int jahr); // [cite: 3]
    // Destruktor (virtuell für Polymorphie)
    virtual ~Medium() = default; // [cite: 4]
    // Getter-Funktionen (inline)
    inline int getId() const { return id; }                      // [cite: 5, 6]
    inline const std::string &getTitel() const { return titel; } // [cite: 6, 7]
    inline int getJahr() const { return jahr; }                  // [cite: 7, 8]
    inline int getAlter() const { return 2021 - jahr; }          // [cite: 8, 9]

    // Virtuelle Funktion für polymorphe Ausgabe
    virtual void druckeDaten() const = 0; // [cite: 9]
};
#endif