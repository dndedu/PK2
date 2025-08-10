#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template <typename T>
class Matrix
{
private:
    T **m; // Zeiger auf Array von Zeigern (für 2D-Array)
    int n; // Dimension der Matrix (n x n)

    // Hilfsfunktion für die Speicherverwaltung
    void allocateMemory()
    {
        // Erstelle Array von n Zeigern
        m = new T *[n];

        // Für jeden Zeiger erstelle Array der Länge n (eine Zeile)
        for (int i = 0; i < n; ++i)
        {
            m[i] = new T[n];
        }
    }

    void deallocateMemory()
    {
        if (m != nullptr)
        {
            // Erst alle Zeilen freigeben
            for (int i = 0; i < n; ++i)
            {
                delete[] m[i];
            }
            // Dann das Array der Zeiger freigeben
            delete[] m;
            m = nullptr;
        }
    }

public:
    // Konstruktor - erzeugt n x n Matrix
    explicit Matrix(int dimension) : n(dimension)
    {
        allocateMemory();

        // Initialisiere alle Werte mit 0 (oder Default-Wert von T)
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                m[i][j] = T{}; // C++11 uniform initialization
            }
        }
    }

    // Destruktor - gibt dynamisch allokierten Speicher frei
    ~Matrix()
    {
        deallocateMemory();
    }

    // Kopier-Konstruktor - für deep copy
    Matrix(const Matrix<T> &other) : n(other.n)
    {
        allocateMemory();

        // Kopiere alle Werte aus der anderen Matrix
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                m[i][j] = other.m[i][j];
            }
        }
    }

    // Zuweisungsoperator - für deep copy bei Zuweisung
    Matrix<T> &operator=(const Matrix<T> &other)
    {
        // Selbstzuweisung prüfen
        if (this == &other)
        {
            return *this;
        }

        // Alten Speicher freigeben
        deallocateMemory();

        // Neue Dimension setzen und Speicher allokieren
        n = other.n;
        allocateMemory();

        // Werte kopieren
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                m[i][j] = other.m[i][j];
            }
        }

        return *this;
    }

    // Setter-Funktion - setzt Wert an Position (i,j)
    void set(int i, int j, const T &value)
    {
        // Bounds-Checking könnte hier hinzugefügt werden
        m[i][j] = value;
    }

    // Getter-Funktion - gibt Wert an Position (i,j) zurück (konstant)
    T get(int i, int j) const
    {
        // Bounds-Checking könnte hier hinzugefügt werden
        return m[i][j];
    }

    // Multiplikationsoperator - multipliziert zwei Matrizen
    Matrix<T> operator*(const Matrix<T> &other) const
    {
        // Erstelle Ergebnis-Matrix mit gleicher Dimension
        Matrix<T> result(n);

        // Standard-Matrixmultiplikation: C[i][j] = Σ(A[i][k] * B[k][j])
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                result.m[i][j] = T{}; // Initialisiere mit 0

                // Skalarprodukt der i-ten Zeile mit j-ter Spalte
                for (int k = 0; k < n; ++k)
                {
                    result.m[i][j] += m[i][k] * other.m[k][j];
                }
            }
        }

        return result;
    }

    // Getter für Dimension (konstante inline Funktion)
    inline int getDimension() const
    {
        return n;
    }

    // Friend-Funktion für Ausgabeoperator
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Matrix<U> &matrix);
};

// Ausgabeoperator - formatierte Ausgabe der Matrix
// Muss außerhalb der Klasse definiert werden da es freie Funktion ist
template <typename T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &matrix)
{
    for (int i = 0; i < matrix.n; ++i)
    {
        for (int j = 0; j < matrix.n; ++j)
        {
            os << matrix.m[i][j];

            // Leerzeichen zwischen Spalten, außer nach letzter Spalte
            if (j < matrix.n - 1)
            {
                os << " ";
            }
        }

        // Zeilenumbruch nach jeder Zeile, außer nach letzter Zeile
        if (i < matrix.n - 1)
        {
            os << std::endl;
        }
    }

    return os;
}

#endif // MATRIX_H