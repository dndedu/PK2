using System;
using Fh.Pk2.Devices;
using Fh.Pk2.Commands;
using Fh.Pk2.Rc;

namespace Praktikum13
{
    /// <summary>
    /// Hauptprogramm - Demonstriert die Verwendung der programmierbaren Fernbedienung
    /// </summary>
    class Program
    {
        static void Main(string[] args)
        {
            // Erstelle eine neue Fernbedienung
            RemoteControl remoteControl = new RemoteControl();

            // Erstelle die Geräte-Objekte
            CdPlayer cdPlayer = new CdPlayer();
            Garagentor garagentor = new Garagentor();

            // Erstelle die Kommandos für den CD-Player
            CdPlayerStartCommand cdPlayerStart = new CdPlayerStartCommand(cdPlayer);
            CdPlayerStoppCommand cdPlayerStopp = new CdPlayerStoppCommand(cdPlayer);

            // Erstelle die Kommandos für das Garagentor
            GaragentorHochCommand garagentorHoch = new GaragentorHochCommand(garagentor);
            GaragentorRunterCommand garagentorRunter = new GaragentorRunterCommand(garagentor);

            // Programmiere die Fernbedienung
            // Tastenpaar 0: CD-Player Steuerung
            remoteControl.SetCommand(0, cdPlayerStart, cdPlayerStopp);

            // Tastenpaar 1: Garagentor Steuerung
            remoteControl.SetCommand(1, garagentorHoch, garagentorRunter);

            // Führe die gewünschte Ausgabe-Sequenz aus
            Console.WriteLine("=== Remote Control Test ===");

            // CD-Player start
            remoteControl.PressOn(0);

            // Garagentor hoch
            remoteControl.PressOn(1);

            // CD-Player stopp
            remoteControl.PressOff(0);

            // Garagentor runter
            remoteControl.PressOff(1);

            Console.WriteLine("\nProgramm beendet. Drücke eine beliebige Taste...");
            Console.ReadKey();
        }
    }
}