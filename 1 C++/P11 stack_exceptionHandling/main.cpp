#include <iostream>
#include "stack_new.h"
#include "stack_exception.h"

int main()
{
    // Stack mit Werten erstellen
    stack<long> s{};
    stack<double> d{};

    // Dynamisch allokierter Stack
    stack<long> *u = new stack<long>{};
    u->push(100);

    // Stack mit Werten befüllen
    int i;
    for (i = 1; i <= 10; i++)
    {
        s.push(i);
    }

    // Copy-Konstruktor testen
    stack<long> t = s;

    std::cout << "Normale pop-Operationen:" << std::endl;
    std::cout << "t.pop(): " << t.pop() << std::endl;
    std::cout << "s.pop(): " << s.pop() << std::endl;

    // Alle Elemente aus Stack entfernen
    std::cout << "\nAlle Elemente aus Stack s entfernen:" << std::endl;
    while (!s.is_empty())
    {
        std::cout << "s.pop(): " << s.pop() << std::endl;
    }

    // Jetzt ist der Stack leer - pop() sollte Exception werfen
    std::cout << "\nVersuch pop() auf leerem Stack:" << std::endl;
    try
    {
        // Das wird eine Exception werfen
        long result = s.pop();
        std::cout << "Unerwartetes Ergebnis: " << result << std::endl;
    }
    catch (const empty_stack_exception &e)
    {
        std::cout << "Exception gefangen: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        // Fallback für andere Standard-Exceptions
        std::cout << "Andere Exception gefangen: " << e.what() << std::endl;
    }

    // Weitere Tests mit leerem Stack
    std::cout << "\nWeitere Tests mit leerem Stack:" << std::endl;

    // Test mit double-Stack
    try
    {
        double result = d.pop();
        std::cout << "Unerwartetes Ergebnis: " << result << std::endl;
    }
    catch (const empty_stack_exception &e)
    {
        std::cout << "Exception bei double-Stack: " << e.what() << std::endl;
    }

    // Speicher freigeben
    delete u;

    std::cout << "\nProgramm erfolgreich beendet." << std::endl;
    return 0;
}