using Fh.Pk2.Devices;

namespace Fh.Pk2.Commands
{
    /// <summary>
    /// Abstraktes Command Interface - definiert die Execute-Methode für alle Kommandos
    /// </summary>
    public abstract class Command
    {
        /// <summary>
        /// Führt das spezifische Kommando aus
        /// </summary>
        public abstract void Execute();
    }

    /// <summary>
    /// Kommando zum Starten des CD-Players
    /// </summary>
    public class CdPlayerStartCommand : Command
    {
        private readonly CdPlayer _cdPlayer;

        /// <summary>
        /// Konstruktor - erhält Referenz auf das CD-Player Gerät
        /// </summary>
        /// <param name="cdPlayer">Das zu steuernde CD-Player Objekt</param>
        public CdPlayerStartCommand(CdPlayer cdPlayer)
        {
            _cdPlayer = cdPlayer;
        }

        /// <summary>
        /// Führt den Start-Befehl am CD-Player aus
        /// </summary>
        public override void Execute()
        {
            _cdPlayer.Start();
        }
    }

    /// <summary>
    /// Kommando zum Stoppen des CD-Players
    /// </summary>
    public class CdPlayerStoppCommand : Command
    {
        private readonly CdPlayer _cdPlayer;

        /// <summary>
        /// Konstruktor - erhält Referenz auf das CD-Player Gerät
        /// </summary>
        /// <param name="cdPlayer">Das zu steuernde CD-Player Objekt</param>
        public CdPlayerStoppCommand(CdPlayer cdPlayer)
        {
            _cdPlayer = cdPlayer;
        }

        /// <summary>
        /// Führt den Stopp-Befehl am CD-Player aus
        /// </summary>
        public override void Execute()
        {
            _cdPlayer.Stopp();
        }
    }

    /// <summary>
    /// Kommando zum Öffnen des Garagentors
    /// </summary>
    public class GaragentorHochCommand : Command
    {
        private readonly Garagentor _garagentor;

        /// <summary>
        /// Konstruktor - erhält Referenz auf das Garagentor Gerät
        /// </summary>
        /// <param name="garagentor">Das zu steuernde Garagentor Objekt</param>
        public GaragentorHochCommand(Garagentor garagentor)
        {
            _garagentor = garagentor;
        }

        /// <summary>
        /// Führt den Hoch-Befehl am Garagentor aus
        /// </summary>
        public override void Execute()
        {
            _garagentor.Hoch();
        }
    }

    /// <summary>
    /// Kommando zum Schließen des Garagentors
    /// </summary>
    public class GaragentorRunterCommand : Command
    {
        private readonly Garagentor _garagentor;

        /// <summary>
        /// Konstruktor - erhält Referenz auf das Garagentor Gerät
        /// </summary>
        /// <param name="garagentor">Das zu steuernde Garagentor Objekt</param>
        public GaragentorRunterCommand(Garagentor garagentor)
        {
            _garagentor = garagentor;
        }

        /// <summary>
        /// Führt den Runter-Befehl am Garagentor aus
        /// </summary>
        public override void Execute()
        {
            _garagentor.Runter();
        }
    }
}