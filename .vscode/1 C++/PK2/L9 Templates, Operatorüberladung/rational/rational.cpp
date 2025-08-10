#include "rational.h"

rational::rational(int z, int n) : zaehler{z}, nenner{n} {}

// // option 1 & 3
// rational operator*(rational l, rational r)
// {
//     // rational neu{l.zaehler * r.zaehler, l.nenner * r.nenner};
//     // return neu;
//     return rational{l.zaehler * r.zaehler, l.nenner * r.nenner};
// }

// option 2
rational rational::operator*(rational r)
{
    rational neu{this->zaehler * r.zaehler, this->nenner * r.nenner};
    return neu;
}

std::ostream &operator<<(std::ostream &out, rational r)
{
    out << "(" << r.zaehler << "/" << r.nenner << ")";
    return out;
    // return out << "(" << r.zaehler << "/" << r.nenner << ")";
}