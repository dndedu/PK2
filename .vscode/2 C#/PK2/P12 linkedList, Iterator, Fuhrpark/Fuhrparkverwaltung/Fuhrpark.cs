using System;

namespace Praktikum12
{
    /// <summary>
    /// Klasse zur Verwaltung eines Fuhrparks
    /// Verwendet die selbst implementierte LinkedList für die interne Verwaltung
    /// </summary>
    public class Fuhrpark
    {
        #region Private Felder

        private LinkedList<Auto> fahrzeuge;  // Interne Liste für Fahrzeugverwaltung

        #endregion

        #region Eigenschaften

        /// <summary>
        /// Eigenschaft für die Anzahl der Fahrzeuge im Fuhrpark
        /// </summary>
        public int AnzahlFahrzeuge
        {
            get { return fahrzeuge.Count; }
        }

        #endregion

        #region Konstruktor

        /// <summary>
        /// Konstruktor - erstellt leeren Fuhrpark
        /// </summary>
        public Fuhrpark()
        {
            fahrzeuge = new LinkedList<Auto>();
            Console.WriteLine("Fuhrpark wurde erstellt");
        }

        #endregion

        #region Öffentliche Methoden

        /// <summary>
        /// Nimmt ein Auto in den Fuhrpark auf
        /// Keine Dubletten-Prüfung wie gefordert
        /// </summary>
        /// <param name="auto">Aufzunehmendes Auto</param>
        public void Aufnehmen(Auto auto)
        {
            if (auto == null)
            {
                Console.WriteLine("Fehler: Auto darf nicht null sein");
                return;
            }

            // Auto zur Liste hinzufügen
            fahrzeuge.Add(auto);
            Console.WriteLine($"Auto aufgenommen: {auto}");
        }

        /// <summary>
        /// Führt eine Inventur durch - gibt alle Fahrzeugdaten aus
        /// Verwendet Iterator für die Durchquerung der Liste
        /// </summary>
        public void Inventur()
        {
            Console.WriteLine("\n=== INVENTUR ===");
            Console.WriteLine($"Anzahl Fahrzeuge: {AnzahlFahrzeuge}");

            if (AnzahlFahrzeuge == 0)
            {
                Console.WriteLine("Keine Fahrzeuge im Fuhrpark vorhanden");
                return;
            }

            Console.WriteLine("Fahrzeugdaten:");
            Console.WriteLine(new string('-', 50));

            // Iterator verwenden um durch alle Fahrzeuge zu iterieren
            IIterator<Auto> iterator = fahrzeuge.GetIterator();
            int nummer = 1;

            while (iterator.HasNext())
            {
                Auto auto = iterator.Next();
                Console.WriteLine($"{nummer,2}. Hersteller: {auto.Hersteller,-15} Baujahr: {auto.Baujahr}");
                nummer++;
            }

            Console.WriteLine(new string('-', 50));
        }

        /// <summary>
        /// Berechnet das durchschnittliche Alter der Fahrzeuge
        /// </summary>
        /// <returns>Durchschnittliches Alter als double-Wert</returns>
        public double BerechneFlottenalter()
        {
            if (AnzahlFahrzeuge == 0)
            {
                Console.WriteLine("Keine Fahrzeuge vorhanden - Flottenalter kann nicht berechnet werden");
                return 0.0;
            }

            // Summe aller Fahrzeugalter berechnen
            int gesamtalter = 0;
            IIterator<Auto> iterator = fahrzeuge.GetIterator();

            while (iterator.HasNext())
            {
                Auto auto = iterator.Next();
                gesamtalter += auto.Alter;
            }

            // Durchschnitt berechnen
            double durchschnittsalter = (double)gesamtalter / AnzahlFahrzeuge;

            Console.WriteLine($"Durchschnittliches Flottenalter: {durchschnittsalter:F1} Jahre");
            return durchschnittsalter;
        }

        /// <summary>
        /// Entfernt ein Fahrzeug an der angegebenen Position
        /// Hilfsmethode für erweiterte Funktionalität
        /// </summary>
        /// <param name="index">Index des zu entfernenden Fahrzeugs</param>
        /// <returns>true wenn erfolgreich entfernt</returns>
        public bool EntferneFahrzeug(int index)
        {
            if (index < 0 || index >= AnzahlFahrzeuge)
            {
                Console.WriteLine($"Ungültiger Index: {index}");
                return false;
            }

            bool erfolg = fahrzeuge.Remove(index);
            if (erfolg)
            {
                Console.WriteLine($"Fahrzeug an Position {index} wurde entfernt");
            }
            else
            {
                Console.WriteLine($"Fehler beim Entfernen des Fahrzeugs an Position {index}");
            }

            return erfolg;
        }

        #endregion
    }
}