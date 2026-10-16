using System;

namespace Fh.Pk2.Devices
{
    /// <summary>
    /// CD-Player Gerät mit Start/Stopp Funktionalität
    /// </summary>
    public class CdPlayer
    {
        /// <summary>
        /// Startet den CD-Player
        /// </summary>
        public void Start()
        {
            Console.WriteLine("CD-Player start");
        }

        /// <summary>
        /// Stoppt den CD-Player
        /// </summary>
        public void Stopp()
        {
            Console.WriteLine("CD-Player stopp");
        }
    }

    /// <summary>
    /// Garagentor Gerät mit Hoch/Runter Funktionalität
    /// </summary>
    public class Garagentor
    {
        /// <summary>
        /// Öffnet das Garagentor (bewegt es nach oben)
        /// </summary>
        public void Hoch()
        {
            Console.WriteLine("Garagentor hoch");
        }

        /// <summary>
        /// Schließt das Garagentor (bewegt es nach unten)
        /// </summary>
        public void Runter()
        {
            Console.WriteLine("Garagentor runter");
        }
    }
}