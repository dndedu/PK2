// Program.cs
using System;

namespace Praktikum13
{
    /// <summary>
    /// Hauptprogramm zum Testen der implementierten Klassen für Praktikum 13.
    /// </summary>
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("=== Praktikum 13, C# Implementation ===\n");

            TestLinkedListErweitert();

            TestFuhrparkMitEvent();

            TestRationalKlasse();

            Console.WriteLine("\nProgramm beendet. Drücken Sie eine beliebige Taste...");
            Console.ReadKey();
        }

        /// <summary>
        /// Aufgabe 1, Testet die erweiterte LinkedList Implementierung mit Count Property und Indexer.
        /// </summary>
        static void TestLinkedListErweitert()
        {
            Console.WriteLine("=== Test Erweiterte LinkedList ===");

            LinkedList<Auto> liste = new LinkedList<Auto>();

            Console.WriteLine("Füge Autos über Indexer an Position Count hinzu:");
            liste[liste.Count] = new Auto("Audi", 2021);
            Console.WriteLine($"Hinzugefügt: {liste[liste.Count - 1]}");
            liste[liste.Count] = new Auto("Tesla", 2021);
            Console.WriteLine($"Hinzugefügt: {liste[liste.Count - 1]}");
            Console.WriteLine($"Anzahl Elemente in der Liste: {liste.Count}");

            Console.WriteLine("\nAusgabe der Liste mittels Indexer:");
            for (int i = 0; i < liste.Count; i++)
            {
                Console.WriteLine($"[{i}]: {liste[i]}");
            }

            // Test der Bereichsüberschreitung für den Indexer
            try
            {
                Console.WriteLine("\nVersuche, auf ungültigen Index zuzugreifen (liste[liste.Count+1]):");
                var dummy = liste[liste.Count + 1];
            }
            catch (IndexOutOfRangeException ioorexc)
            {
                Console.WriteLine($"IndexOutOfRangeException aufgrund Zugriffs auf ungültigen Index liste[liste.Count+1] erwartet: {ioorexc.Message}");
            }

            try
            {
                Console.WriteLine("Versuche, an falscher Stelle mit dem Indexer zu setzen (liste[0] = ...):");
                liste[0] = new Auto("Fehlerauto", 2000);
            }
            catch (IndexOutOfRangeException ioorexc)
            {
                Console.WriteLine($"IndexOutOfRangeException aufgrund Zugriffs auf ungültigen Index liste[0] = ... erwartet: {ioorexc.Message}");
            }
            Console.WriteLine();
        }

        /// <summary>
        /// Aufgabe 2, Testet die Fuhrpark Klasse mit dem implementierten Event.
        /// </summary>
        static void TestFuhrparkMitEvent()
        {
            Console.WriteLine("=== Test Fuhrpark mit Event ===");

            Fuhrpark fuhrpark = new Fuhrpark();
            Info infoAnzeige = new Info();
            // Registrieren der Methode der Info-Klasse für das AutoHinzugefuegt-Event
            fuhrpark.AutoHinzugefuegt += infoAnzeige.AutoAufgenommenHandler;

            Console.WriteLine("\nFüge Fahrzeuge zum Fuhrpark hinzu:");
            fuhrpark.Aufnehmen(new Auto("BMW", 2022));
            fuhrpark.Aufnehmen(new Auto("Ford", 2022));
            fuhrpark.Aufnehmen(new Auto("Mercedes", 2022));

            // Inventur zur Überprüfung
            fuhrpark.Inventur();

            // Deregistrieren des Events zur Demonstration
            fuhrpark.AutoHinzugefuegt -= infoAnzeige.AutoAufgenommenHandler;
            Console.WriteLine("\nInfo-Anzeige vom Fuhrpark-Event abgemeldet.");
            fuhrpark.Aufnehmen(new Auto("Mitsubishi", 2022));
            Console.WriteLine("Ein weiteres Auto wurde hinzugefügt, aber Info-Klasse ist abgemeldet.");

            // Durchschnittsalter der Fahrzeugflotte
            fuhrpark.BerechneDurchschnittFlottenalter();

            Console.WriteLine();
        }

        /// <summary>
        /// Aufgabe 3, Testet die Implementierung der Klasse Rational
        /// </summary>
        static void TestRationalKlasse()
        {
            Console.WriteLine("=== Test Rational Klasse ===");

            Rational a = new Rational(2, 4);
            Rational b = new Rational(9, 5);

            Rational c = a * b;

            Console.WriteLine($"{a} * {b} = {c}\n");
            // Erwartete Ausgabe: (2/4)*(9/5)=(18/20)

            try
            {
                Console.WriteLine("Versuche, Rational mit Nenner 0 zu erstellen:");
                Rational rFehler = new Rational(1, 0);
            }
            catch (ArgumentException aexc)
            {
                Console.WriteLine($"ArgumentException erwartet aufgrund der Erstellung eines Bruches mit dem Nenner 0: {aexc.Message}\n");
            }

            Console.WriteLine();
        }
    }
}