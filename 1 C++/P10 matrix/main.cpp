#include <iostream>
#include "Matrix.h"

int main()
{
    // Erstelle 2x2 Matrix mit int-Werten
    Matrix<int> m(2);

    // Setze Matrixwerte entsprechend der Aufgabe
    m.set(0, 0, 1); // Erste Zeile, erste Spalte
    m.set(0, 1, 2); // Erste Zeile, zweite Spalte
    m.set(1, 0, 3); // Zweite Zeile, erste Spalte
    m.set(1, 1, 4); // Zweite Zeile, zweite Spalte

    // Ausgabe entsprechend der gewünschten Formatierung
    std::cout << m << std::endl
              << "*" << std::endl
              << m << std::endl
              << "=" << std::endl
              << m * m;

    std::cout << std::endl
              << std::endl;

    // Zusätzlicher Test mit 3x3 Matrix
    std::cout << "Test mit 3x3 Matrix:" << std::endl;
    Matrix<int> m3(3);

    // Einheitsmatrix erstellen
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            m3.set(i, j, (i == j) ? 1 : 0);
        }
    }

    std::cout << "Einheitsmatrix:" << std::endl;
    std::cout << m3 << std::endl;

    // Test des Kopier-Konstruktors
    Matrix<int> m3_copy = m3;
    std::cout << "Kopie der Einheitsmatrix:" << std::endl;
    std::cout << m3_copy << std::endl;

    return 0;
}