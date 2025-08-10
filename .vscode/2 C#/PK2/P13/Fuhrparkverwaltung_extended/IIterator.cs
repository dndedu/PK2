// IIterator.cs (Unverändert von Praktikum 12, da als Basis benötigt)
using System;

namespace Praktikum13
{
    /// <summary>
    /// Schnittstelle für Iterator-Implementierungen
    /// Entspricht der Iterator-Klasse aus der C++ Version
    /// </summary>
    /// <typeparam name="T">Typ der Elemente über die iteriert wird</typeparam>
    public interface IIterator<T>
    {
        /// <summary>
        /// Prüft ob zumindest ein weiteres Element vorhanden ist
        /// </summary>
        /// <returns>true wenn vorhanden, ansonsten false</returns>
        bool HasNext();

        /// <summary>
        /// Liefert das nächste Element und bewegt den Iterator weiter
        /// </summary>
        /// <returns>Das nächste Element</returns>
        T Next();
    }
}