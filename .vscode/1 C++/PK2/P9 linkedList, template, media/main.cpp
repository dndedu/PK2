#include <iostream>
#include "linkedList.h" // Include the templated LinkedList
#include "audio.h"      // Include Audio class
#include "bild.h"       // Include Bild class

using namespace std;
using namespace fhdo_pk2;

// Callback-Funktion zum Drucken der Mediendaten
void druckeMediendaten(Medium *medium)
{
    if (medium)
    {
        medium->druckeDaten(); // Ruft die polymorphe Funktion auf
    }
    else
    {
        cout << "Fehler: Versuch, ein NULL-Medienobjekt zu drucken." << endl;
    }
}

// Callback-Funktion zum Löschen von Medienobjekten
void loescheMedium(Medium *medium)
{
    if (medium)
    {
        cout << "Lösche Medium (ID: " << medium->getId() << ", Titel: \"" << medium->getTitel() << "\")." << endl;
        delete medium; // Löscht das tatsächliche Medium-Objekt
    }
}

int main()
{
    // Erstellen einer LinkedList zum Speichern von Medium-Pointern [cite: 161]
    LinkedList<Medium *> medienListe;

    // 1. Audio- und Bild-Objekte in der LinkedList speichern [cite: 159]
    cout << "--- Medienobjekte hinzufügen ---" << endl;
    Medium *audio1 = new Audio("Bohemian Rhapsody", 1975, "Queen", 354);
    medienListe.append(audio1);
    Medium *bild1 = new Bild("Sonnenuntergang am Meer", 2020, "Malediven");
    medienListe.append(bild1);
    Medium *audio2 = new Audio("Hotel California", 1976, "Eagles", 390);
    medienListe.insert(audio2, 0); // Am Anfang einfügen
    Medium *bild2 = new Bild("Berggipfel", 2019, "Alpen");
    medienListe.insert(bild2, 2); // In der Mitte einfügen

    cout << "\n--- Aktuelle Medienliste ---" << endl;
    medienListe.visit_all(druckeMediendaten); // Alle Daten ausgeben [cite: 159]
    cout << "Anzahl der Elemente in der Liste: " << medienListe.getSize() << endl;

    // 2. Test der get()-Funktion
    cout << "\n--- Test der get()-Funktion ---" << endl;
    Medium *retrievedMedium = medienListe.get(1);
    if (retrievedMedium)
    {
        cout << "Element an Position 1: ";
        retrievedMedium->druckeDaten();
    }
    else
    {
        cout << "Element an Position 1 nicht gefunden." << endl;
    }

    retrievedMedium = medienListe.get(10); // Ungültige Position
    if (!retrievedMedium)
    {
        cout << "Element an Position 10 nicht gefunden (korrekt)." << endl;
    }

    // 3. Alle in der Liste verzeichneten Medien löschen mit visit_all [cite: 160]
    // Zuerst die Objekte, auf die die Listenelemente zeigen, löschen
    cout << "\n--- Medienobjekte löschen via visit_all ---" << endl;
    medienListe.visit_all(loescheMedium); // Dies löscht die eigentlichen Audio/Bild-Objekte

    // Anschließend die "leeren" Listenelemente separat über die remove-Funktion löschen. [cite: 160, 162]
    cout << "\n--- Listenelemente entfernen ---" << endl;
    // Wir entfernen alle Elemente, bis die Liste leer ist.
    while (medienListe.getSize() > 0)
    {
        cout << "Entferne Element, Listenlänge vorher: " << medienListe.getSize() << endl;
        medienListe.remove(0); // Immer das erste Element entfernen, bis die Liste leer ist.
    }

    cout << "\n--- Medienliste nach dem Entfernen ---" << endl;
    medienListe.visit_all(druckeMediendaten); // Sollte nichts ausgeben
    cout << "Anzahl der Elemente in der Liste: " << medienListe.getSize() << endl;

    // Test mit Copy-Konstruktor
    cout << "\n--- Test des Copy-Konstruktors ---" << endl;
    LinkedList<Medium *> originalListe;
    Medium *testAudio = new Audio("Test Song", 2023, "Test Artist", 100);
    originalListe.append(testAudio);

    LinkedList<Medium *> kopierteListe = originalListe; // Verwendet den Kopier-Konstruktor
    cout << "Original Liste:" << endl;
    originalListe.visit_all(druckeMediendaten);
    cout << "Kopierte Liste:" << endl;
    kopierteListe.visit_all(druckeMediendaten);

    // Aufräumen der originalen Liste (nur die Knoten, die Objekte wurden bereits in der visit_all gelöscht,
    // oder hier explizit, wenn nicht durch visit_all gelöscht).
    // Da die Objekte via visit_all gelöscht wurden, löschen wir hier nur die Nodes.
    // Falls die Objekte nicht durch visit_all gelöscht worden wären, müsste man sie hier löschen.
    // Die kopierte Liste hält dann Pointer auf bereits gelöschte Objekte. Dies ist die Konsequenz
    // des Speicherns von Zeigertypen ohne tiefe Kopie der Zielobjekte.
    originalListe.remove(0); // Entfernt den Knoten aus der originalliste

    // Der Zeiger in der kopierten Liste zeigt nun auf ein bereits gelöschtes Objekt.
    // Dies verdeutlicht, dass die LinkedList nur den Speicher der Nodes verwaltet und nicht
    // den Speicher der Objekte, auf die T zeigt.
    // Um die kopierte Liste korrekt zu bereinigen, müsste auch sie gecleart oder ihre Inhalte behandelt werden.
    // Hier wird davon ausgegangen, dass das Objekt bereits über die Bereinigung der originalliste gelöscht wurde.
    // Dies entspricht der Anforderung, dass die Liste nur Zeigertypen verwaltet.

    return 0;
}