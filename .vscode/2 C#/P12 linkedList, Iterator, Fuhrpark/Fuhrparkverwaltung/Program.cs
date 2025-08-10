using System;

namespace Praktikum12
{
    /// <summary>
    /// Hauptprogramm zum Testen der implementierten Klassen
    /// Testet LinkedList, Auto und Fuhrpark wie gefordert
    /// </summary>
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("=== Praktikum 12 - C# Implementation ===\n");

            // Test der LinkedList Klasse
            TestLinkedList();

            // Test der Auto Klasse
            TestAutoKlasse();

            // Test der Fuhrpark Klasse
            TestFuhrpark();

            Console.WriteLine("\nProgramm beendet. Drücken Sie eine beliebige Taste...");
            Console.ReadKey();
        }

        /// <summary>
        /// Testet die LinkedList Implementierung
        /// </summary>
        static void TestLinkedList()
        {
            Console.WriteLine("=== Test LinkedList ===");

            // String-Liste testen
            LinkedList<string> stringListe = new LinkedList<string>();

            // Elemente hinzufügen
            stringListe.Add("Erstes Element");
            stringListe.Add("Zweites Element");
            stringListe.Add("Drittes Element");

            Console.WriteLine($"Anzahl Elemente: {stringListe.Count}");
            stringListe.PrintAll();

            // Element entfernen
            Console.WriteLine("\nElement an Index 1 entfernen...");
            stringListe.Remove(1);
            stringListe.PrintAll();

            // Integer-Liste testen (Generizität)
            Console.WriteLine("\n--- Test mit Integer-Liste ---");
            LinkedList<int> intListe = new LinkedList<int>();
            intListe.Add(10);
            intListe.Add(20);
            intListe.Add(30);
            intListe.PrintAll();

            Console.WriteLine();
        }

        /// <summary>
        /// Testet die Auto Klasse mit Eigenschaften
        /// </summary>
        static void TestAutoKlasse()
        {
            Console.WriteLine("=== Test Auto Klasse ===");

            // Auto mit Konstruktor erstellen
            Auto auto1 = new Auto("BMW", 2018);
            Console.WriteLine($"Auto1: {auto1}");

            // Auto mit parameterlosem Konstruktor
            Auto auto2 = new Auto();
            auto2.Hersteller = "Mercedes";
            auto2.Baujahr = 2020;
            Console.WriteLine($"Auto2: {auto2}");

            // Alter-Eigenschaft testen
            Console.WriteLine($"Auto1 Alter: {auto1.Alter} Jahre");
            Console.WriteLine($"Auto2 Alter: {auto2.Alter} Jahre");

            // Validierung testen
            try
            {
                Auto autoFehler = new Auto("", 2022);
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine($"Validierung erfolgreich: {ex.Message}");
            }

            Console.WriteLine();
        }

        /// <summary>
        /// Testet die Fuhrpark Klasse mit allen geforderten Methoden
        /// </summary>
        static void TestFuhrpark()
        {
            Console.WriteLine("=== Test Fuhrpark ===");

            // Fuhrpark erstellen
            Fuhrpark fuhrpark = new Fuhrpark();

            // Verschiedene Autos hinzufügen
            fuhrpark.Aufnehmen(new Auto("Volkswagen", 2019));
            fuhrpark.Aufnehmen(new Auto("Audi", 2021));
            fuhrpark.Aufnehmen(new Auto("BMW", 2017));
            fuhrpark.Aufnehmen(new Auto("Mercedes", 2020));
            fuhrpark.Aufnehmen(new Auto("Porsche", 2022));

            // Inventur durchführen
            fuhrpark.Inventur();

            // Durchschnittliches Flottenalter berechnen
            Console.WriteLine();
            double durchschnittsalter = fuhrpark.BerechneFlottenalter();

            // Zusätzliche Tests
            Console.WriteLine("\n--- Zusätzliche Tests ---");
            Console.WriteLine($"Anzahl Fahrzeuge im Fuhrpark: {fuhrpark.AnzahlFahrzeuge}");

            // Ein Fahrzeug entfernen (erweiterte Funktionalität)
            fuhrpark.EntferneFahrzeug(2); // BMW entfernen

            // Erneute Inventur nach Entfernung
            fuhrpark.Inventur();
            fuhrpark.BerechneFlottenalter();

            // Test mit leerem Fuhrpark
            Console.WriteLine("\n--- Test leerer Fuhrpark ---");
            Fuhrpark leereFuhrpark = new Fuhrpark();
            leereFuhrpark.Inventur();
            leereFuhrpark.BerechneFlottenalter();
        }
    }
}