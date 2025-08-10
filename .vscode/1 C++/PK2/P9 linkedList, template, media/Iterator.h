#ifndef ITERATOR_H
#define ITERATOR_H

namespace fhdo_pk2
{

    // Abstrakte Template Iterator-Klasse (reine Schnittstelle) [cite: 30]
    template <typename T>
    class Iterator
    {
    public:
        // Virtueller Destruktor [cite: 29]
        virtual ~Iterator() = default;

        // Prüft, ob noch weitere Elemente vorhanden sind [cite: 30]
        virtual bool hasNext() = 0;

        // Liefert das nächste Element [cite: 31]
        virtual T next() = 0;
    };

} // namespace fhdo_pk2

#endif // ITERATOR_H