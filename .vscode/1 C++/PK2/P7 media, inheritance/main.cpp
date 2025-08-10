#include <iostream>
#include "Audio.h"
#include "Bild.h"

int main()
{
    // Array mit zwei Zeigern auf Medium-Objekte erstellen
    Medium *medien[2];

    // Audio-Objekt erstellen und im Array speichern
    medien[0] = new Audio("It Means Nothing", 2007, "Stereophonics", 229);

    // Bild-Objekt erstellen und im Array speichern
    medien[1] = new Bild("Gebaeude FB Informatik", 2020, "Dortmund");

    // Für beide Objekte druckeDaten über das Array aufrufen
    for (int i = 0; i < 2; i++)
    {
        medien[i]->druckeDaten();
    }

    // Speicher wieder freigeben
    for (int i = 0; i < 2; i++)
    {
        delete medien[i];
    }

    return 0;
}