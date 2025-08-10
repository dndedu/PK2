using Fh.Pk2.Commands;

namespace Fh.Pk2.Rc
{
    /// <summary>
    /// RemoteControl - Programmierbare Fernbedienung mit 4 On/Off Tastenpaaren
    /// </summary>
    public class RemoteControl
    {
        // Arrays für die On- und Off-Kommandos (4 Tastenpaare)
        private readonly Command[] _onCommands;
        private readonly Command[] _offCommands;

        /// <summary>
        /// Konstruktor - Initialisiert die Fernbedienung mit leeren Kommando-Arrays
        /// </summary>
        public RemoteControl()
        {
            _onCommands = new Command[4];  // 4 On-Tasten
            _offCommands = new Command[4]; // 4 Off-Tasten
        }

        /// <summary>
        /// Programmiert ein Tastenpaar mit spezifischen On/Off-Kommandos
        /// </summary>
        /// <param name="slot">Tastenpaar-Index (0-3)</param>
        /// <param name="onCommand">Kommando für die On-Taste</param>
        /// <param name="offCommand">Kommando für die Off-Taste</param>
        public void SetCommand(int slot, Command onCommand, Command offCommand)
        {
            // Überprüfung des gültigen Slot-Bereichs
            if (slot >= 0 && slot < 4)
            {
                _onCommands[slot] = onCommand;
                _offCommands[slot] = offCommand;
            }
        }

        /// <summary>
        /// Drückt die On-Taste des angegebenen Tastenpaars
        /// </summary>
        /// <param name="slot">Tastenpaar-Index (0-3)</param>
        public void PressOn(int slot)
        {
            // Überprüfung des gültigen Slot-Bereichs und ob Kommando gesetzt ist
            if (slot >= 0 && slot < 4 && _onCommands[slot] != null)
            {
                _onCommands[slot].Execute();
            }
        }

        /// <summary>
        /// Drückt die Off-Taste des angegebenen Tastenpaars
        /// </summary>
        /// <param name="slot">Tastenpaar-Index (0-3)</param>
        public void PressOff(int slot)
        {
            // Überprüfung des gültigen Slot-Bereichs und ob Kommando gesetzt ist
            if (slot >= 0 && slot < 4 && _offCommands[slot] != null)
            {
                _offCommands[slot].Execute();
            }
        }
    }
}