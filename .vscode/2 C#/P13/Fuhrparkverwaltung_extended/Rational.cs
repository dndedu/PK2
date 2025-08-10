// Rational.cs
using System;

namespace Praktikum13
{
    /// <summary>
    /// (Aufgabe 3) Klasse Rational zur Darstellung und Multiplikation rationaler Zahlen.
    /// </summary>
    public class Rational
    {
        #region Eigenschaften

        /// <summary>
        /// Zähler der rationalen Zahl.
        /// </summary>
        public int Zaehler { get; }

        /// <summary>
        /// Nenner der rationalen Zahl.
        /// </summary>
        public int Nenner { get; }

        #endregion

        #region Konstruktor

        /// <summary>
        /// Konstruktor für eine rationale Zahl.
        /// </summary>
        /// <param name="zaehler">Der Zähler der rationalen Zahl.</param>
        /// <param name="nenner">Der Nenner der rationalen Zahl.</param>
        /// <exception cref="ArgumentException">Wird geworfen, wenn der Nenner 0 ist.</exception>
        public Rational(int zaehler, int nenner)
        {
            if (nenner == 0)
            {
                throw new ArgumentException("Der Nenner einer rationalen Zahl darf nicht 0 sein.");
            }
            Zaehler = zaehler;
            Nenner = nenner;
        }

        #endregion

        #region Operatoren

        /// <summary>
        /// Überladung des Multiplikationsoperators für zwei rationale Zahlen.
        /// (Aufgabe 3)
        /// </summary>
        /// <param name="a">Die erste rationale Zahl.</param>
        /// <param name="b">Die zweite rationale Zahl.</param>
        /// <returns>Das Produkt der beiden rationalen Zahlen.</returns>
        public static Rational operator *(Rational a, Rational b)
        {
            // Multiplikation zweier Brüche: (a/b) * (c/d) = (a*c) / (b*d)
            int neuerZaehler = a.Zaehler * b.Zaehler;
            int neuerNenner = a.Nenner * b.Nenner;
            return new Rational(neuerZaehler, neuerNenner);// Ein Kürzen ist nicht erforderlich
        }

        #endregion

        #region Methoden

        /// <summary>
        /// Überschreibt die ToString-Methode, um die rationale Zahl im Format (Zähler/Nenner) auszugeben.
        /// (Aufgabe 3)
        /// </summary>
        /// <returns>Eine String-Darstellung der rationalen Zahl.</returns>
        public override string ToString()
        {
            return $"({Zaehler}/{Nenner})";
        }

        #endregion
    }
}