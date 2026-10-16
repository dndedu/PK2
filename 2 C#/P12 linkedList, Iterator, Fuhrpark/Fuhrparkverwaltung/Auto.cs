using System;

namespace Praktikum12
{
    /// <summary>
    /// Klasse Auto mit Eigenschaften für Hersteller und Baujahr
    /// Implementiert verschiedene Property-Arten wie gefordert
    /// </summary>
    public class Auto
    {
        #region Private Felder

        private string hersteller;  // Backing Field für Hersteller-Eigenschaft

        #endregion

        #region Eigenschaften

        /// <summary>
        /// Eigenschaft für Hersteller mit expliziter Implementierung
        /// Verwendet ein privates Backing Field
        /// </summary>
        public string Hersteller
        {
            get { return hersteller; }
            set
            {
                // Validierung: Hersteller darf nicht null oder leer sein
                if (string.IsNullOrWhiteSpace(value))
                    throw new ArgumentException("Hersteller darf nicht leer sein");
                hersteller = value;
            }
        }

        /// <summary>
        /// Automatische Eigenschaft für Baujahr
        /// Compiler erstellt automatisch Backing Field
        /// </summary>
        public int Baujahr { get; set; }

        /// <summary>
        /// Berechnete Eigenschaft für das Alter des Fahrzeugs
        /// Nur Getter, da sich aus dem Baujahr errechnet
        /// </summary>
        public int Alter
        {
            get { return DateTime.Now.Year - Baujahr; }
        }

        #endregion

        #region Konstruktoren

        /// <summary>
        /// Parameterlöser Konstruktor
        /// </summary>
        public Auto()
        {
            hersteller = "Unbekannt";
            Baujahr = DateTime.Now.Year;
        }

        /// <summary>
        /// Konstruktor mit Parametern
        /// </summary>
        /// <param name="hersteller">Hersteller des Autos</param>
        /// <param name="baujahr">Baujahr des Autos</param>
        public Auto(string hersteller, int baujahr)
        {
            Hersteller = hersteller; // Verwendet die Eigenschaft (mit Validierung)
            Baujahr = baujahr;
        }

        #endregion

        #region Methoden

        /// <summary>
        /// Überschreibt ToString für bessere Ausgabe
        /// </summary>
        /// <returns>String-Darstellung des Auto-Objekts</returns>
        public override string ToString()
        {
            return $"{Hersteller} (Baujahr: {Baujahr}, Alter: {Alter} Jahre)";
        }

        /// <summary>
        /// Überschreibt Equals für Vergleich von Auto-Objekten
        /// </summary>
        /// <param name="obj">Zu vergleichendes Objekt</param>
        /// <returns>true wenn gleich, sonst false</returns>
        public override bool Equals(object obj)
        {
            if (obj is Auto other)
            {
                return Hersteller.Equals(other.Hersteller, StringComparison.OrdinalIgnoreCase)
                       && Baujahr == other.Baujahr;
            }
            return false;
        }

        /// <summary>
        /// Überschreibt GetHashCode für korrekte Hash-Berechnung
        /// </summary>
        /// <returns>Hash-Wert des Objekts</returns>
        public override int GetHashCode()
        {
            return Hersteller.GetHashCode() ^ Baujahr.GetHashCode();
        }

        #endregion
    }
}