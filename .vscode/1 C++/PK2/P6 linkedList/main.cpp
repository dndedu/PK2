#include <iostream>
#include "linkedList.h"

using namespace std;

// Beispiel-Funktion für visit_all
void printText(const char *text)
{
    cout << "Besuche: " << text << endl;
}

// Hauptprogramm zum Testen aller Funktionen
int main()
{
    cout << "=== LinkedList Test Programm ===" << endl;

    LinkedList list;

    // 1. Append-Funktion testen
    cout << "\n1. Append-Funktion testen:" << endl;
    list.append("Erstes Element");
    list.append("Zweites Element");
    list.append("Drittes Element");
    cout << "Liste nach Append-Operationen:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Position " << i << ": " << list.get(i) << endl;
    }

    // 2. Insert-Funktion testen
    cout << "\n2. Insert-Funktion testen:" << endl;
    list.insert("Eingefügt am Anfang", 0);
    list.insert("Eingefügt in der Mitte", 2);
    cout << "Liste nach Insert-Operationen:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Position " << i << ": " << list.get(i) << endl;
    }

    // 3. First und Last testen
    cout << "\n3. First und Last testen:" << endl;
    cout << "Erstes Element: " << list.first() << endl;
    cout << "Letztes Element: " << list.last() << endl;

    // 4. Index_of testen
    cout << "\n4. Index_of testen:" << endl;
    int index = list.index_of("Zweites Element");
    cout << "Index von 'Zweites Element': " << index << endl;
    index = list.index_of("Nicht vorhanden");
    cout << "Index von 'Nicht vorhanden': " << index << endl;

    // 5. Remove-Funktion testen
    cout << "\n5. Remove-Funktion testen:" << endl;
    cout << "Entferne Element an Position 1" << endl;
    list.remove(1);
    cout << "Liste nach Remove:" << endl;
    for (int i = 0; i < 4; i++)
    {
        const char *text = list.get(i);
        if (text)
        {
            cout << "Position " << i << ": " << text << endl;
        }
    }

    // 6. Visit_all testen
    cout << "\n6. Visit_all testen:" << endl;
    list.visit_all(printText);

    // 7. Copy-Konstruktor testen
    cout << "\n7. Copy-Konstruktor testen:" << endl;
    LinkedList list2(list);
    cout << "Kopierte Liste:" << endl;
    for (int i = 0; i < 4; i++)
    {
        const char *text = list2.get(i);
        if (text)
        {
            cout << "Position " << i << ": " << text << endl;
        }
    }

    // 8. Zuweisungsoperator testen
    cout << "\n8. Zuweisungsoperator testen:" << endl;
    LinkedList list3;
    list3.append("Test für Zuweisung");
    list3 = list;
    cout << "Zugewiesene Liste:" << endl;
    for (int i = 0; i < 4; i++)
    {
        const char *text = list3.get(i);
        if (text)
        {
            cout << "Position " << i << ": " << text << endl;
        }
    }

    cout << "\n=== Test beendet ===" << endl;

    return 0;
}