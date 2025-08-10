using System;

namespace Praktikum12
{
    /// <summary>
    /// Schnittstelle für Iterator-Implementierungen
    /// Entspricht der Iterator-Klasse aus der C++ Version
    /// </summary>
    /// <typeparam name="T">Typ der Elemente über die iteriert wird</typeparam>
    public interface IIterator<T>
    {
        /// <summary>
        /// Prüft ob noch weitere Elemente vorhanden sind
        /// </summary>
        /// <returns>true wenn weitere Elemente vorhanden, sonst false</returns>
        bool HasNext();

        /// <summary>
        /// Liefert das nächste Element und bewegt den Iterator weiter
        /// </summary>
        /// <returns>Das nächste Element</returns>
        T Next();
    }
}