using System;

namespace Praktikum12
{
    /// <summary>
    /// Generische einfach verkettete Liste
    /// Implementiert nur Add und Remove Methoden wie gefordert
    /// </summary>
    /// <typeparam name="T">Typ der zu speichernden Elemente</typeparam>
    public class LinkedList<T>
    {
        #region Innere Klassen

        /// <summary>
        /// Innere Klasse für Listenelemente (Node)
        /// Kapselt die Daten und den Zeiger zum nächsten Element
        /// </summary>
        private class ListNode
        {
            public T Data { get; set; }
            public ListNode Next { get; set; }

            public ListNode(T data)
            {
                Data = data;
                Next = null;
            }
        }

        /// <summary>
        /// Innere Klasse für Iterator-Implementierung
        /// Implementiert die IIterator Schnittstelle
        /// </summary>
        private class ListIterator : IIterator<T>
        {
            private ListNode current;

            /// <summary>
            /// Konstruktor für Iterator
            /// </summary>
            /// <param name="start">Startknoten für die Iteration</param>
            public ListIterator(ListNode start)
            {
                current = start;
            }

            /// <summary>
            /// Prüft ob weitere Elemente vorhanden sind
            /// </summary>
            /// <returns>true wenn current nicht null ist</returns>
            public bool HasNext()
            {
                return current != null;
            }

            /// <summary>
            /// Liefert das nächste Element und bewegt Iterator weiter
            /// </summary>
            /// <returns>Daten des aktuellen Knotens</returns>
            public T Next()
            {
                if (current == null)
                    throw new InvalidOperationException("Keine weiteren Elemente vorhanden");

                T data = current.Data;
                current = current.Next;
                return data;
            }
        }

        #endregion

        #region Private Felder

        private ListNode head;    // Erstes Element der Liste
        private int count;        // Anzahl der Elemente

        #endregion

        #region Eigenschaften

        /// <summary>
        /// Eigenschaft für die Anzahl der Elemente in der Liste
        /// </summary>
        public int Count
        {
            get { return count; }
        }

        #endregion

        #region Konstruktor

        /// <summary>
        /// Konstruktor - erstellt leere Liste
        /// </summary>
        public LinkedList()
        {
            head = null;
            count = 0;
        }

        #endregion

        #region Öffentliche Methoden

        /// <summary>
        /// Fügt ein Element am Ende der Liste hinzu
        /// </summary>
        /// <param name="item">Hinzuzufügendes Element</param>
        public void Add(T item)
        {
            ListNode newNode = new ListNode(item);

            // Falls Liste leer ist, wird neuer Knoten zum head
            if (head == null)
            {
                head = newNode;
            }
            else
            {
                // Zum Ende der Liste navigieren
                ListNode current = head;
                while (current.Next != null)
                {
                    current = current.Next;
                }
                // Neuen Knoten am Ende anhängen
                current.Next = newNode;
            }
            count++;
        }

        /// <summary>
        /// Entfernt das Element an der angegebenen Position
        /// </summary>
        /// <param name="index">Index des zu entfernenden Elements (0-basiert)</param>
        /// <returns>true wenn erfolgreich entfernt, false bei ungültigem Index</returns>
        public bool Remove(int index)
        {
            // Prüfung auf gültigen Index
            if (index < 0 || index >= count || head == null)
                return false;

            // Erstes Element entfernen
            if (index == 0)
            {
                head = head.Next;
                count--;
                return true;
            }

            // Element an Position index entfernen
            ListNode current = head;
            // Bis zum Element vor dem zu löschenden navigieren
            for (int i = 0; i < index - 1; i++)
            {
                current = current.Next;
            }

            // Element überspringen (löschen)
            if (current.Next != null)
            {
                current.Next = current.Next.Next;
                count--;
                return true;
            }

            return false;
        }

        /// <summary>
        /// Erstellt einen Iterator für diese Liste
        /// </summary>
        /// <returns>Neuer Iterator</returns>
        public IIterator<T> GetIterator()
        {
            return new ListIterator(head);
        }

        /// <summary>
        /// Gibt alle Elemente der Liste auf der Konsole aus
        /// Verwendet den Iterator für die Durchquerung
        /// </summary>
        public void PrintAll()
        {
            if (head == null)
            {
                Console.WriteLine("Liste ist leer");
                return;
            }

            Console.WriteLine("Listeninhalt:");
            IIterator<T> iterator = GetIterator();
            int index = 0;
            while (iterator.HasNext())
            {
                Console.WriteLine($"[{index}]: {iterator.Next()}");
                index++;
            }
        }

        #endregion
    }
}