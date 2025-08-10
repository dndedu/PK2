#ifndef ITERATOR_H
#define ITERATOR_H

namespace fhdo_pk2
{
    // Abstrakte Iterator-Klasse (reine Schnittstelle)
    class Iterator
    {
    public:
        virtual ~Iterator() = default;

        // Prüft ob noch weitere Elemente vorhanden sind
        virtual bool hasNext() = 0;

        // Liefert das nächste Element
        virtual const char *next() = 0;
    };
}

#endif // ITERATOR_H