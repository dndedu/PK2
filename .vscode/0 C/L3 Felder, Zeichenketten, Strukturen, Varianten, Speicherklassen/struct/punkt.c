#include <stdio.h>
#include <stdlib.h>

typedef struct punkt punkt_s;

struct punkt
{
    int x;
    int y;
};

struct rechteck
{
    punkt_s p1;
    punkt_s p2;
};

struct rechteck create_rechteck_int(int x1, int y1, int x2, int y2)
{
    struct rechteck r;
    r.p1.x = x1;
    r.p1.y = y1;
    r.p2.x = x2;
    r.p2.y = y2;
    return r;
}

struct rechteck create_rechteck_punkt(struct punkt punkt_1, struct punkt punkt_2)
{
    struct rechteck r;
    r.p1.x = punkt_1.x;
    r.p1.y = punkt_1.y;
    r.p2.x = punkt_2.x;
    r.p2.y = punkt_2.y;
    return r;
}

int flaeche(struct rechteck r)
{
    return abs((r.p2.x - r.p1.x) * (r.p2.y - r.p1.y)); // absoluter Betrag, da bei Multiplikation eine mögliche negative Differenz zu einem negativen Ergebnis führen
}

void print_punkt(struct punkt p)
{
    printf("(%d, %d)\n", p.x, p.y);
}

int main()
{
    struct rechteck r = create_rechteck_int(100, 110, 110, 100);
    printf("Fläche = %d\n", flaeche(r)); // TODO absoluten Betrag

    struct punkt p;
    p.x = 100;
    p.y = 200;
    print_punkt(p);
    struct punkt q;
    q.x = 200;
    q.y = 400;
    print_punkt(q);
    struct rechteck s = create_rechteck_punkt(p, q);
    printf("Fläche = %d\n", flaeche(s));

    return 0;
}