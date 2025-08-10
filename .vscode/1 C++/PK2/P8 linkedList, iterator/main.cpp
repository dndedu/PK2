#include <iostream>
#include "linkedList.h"

using namespace std;
using namespace fhdo_pk2;

void ausgabe(const char *text)
{
    std::cout << text << std::endl;
}

// Test der LinkedList-Klasse
int main()
{
    LinkedList liste;
    liste.append("Element 1");
    liste.insert("Element 2", 2);

    // Copy-Konstruktor Test
    LinkedList liste2 = liste;

    cout << "Liste:" << endl;
    liste.visit_all(ausgabe);

    liste.remove(2);

    cout << "Liste:" << endl;
    liste.visit_all(ausgabe);

    cout << "Liste2:" << endl;
    liste2.visit_all(ausgabe);

    // Zusätzlicher Iterator-Test
    cout << "\n=== Iterator Test ===" << endl;
    LinkedList testListe;
    testListe.append("Test 1");
    testListe.append("Test 2");
    testListe.append("Test 3");

    Iterator *it = testListe.iterator();
    cout << "Iterator durchlauf:" << endl;
    while (it->hasNext())
    {
        cout << "- " << it->next() << endl;
    }
    delete it;

    return 0;
}