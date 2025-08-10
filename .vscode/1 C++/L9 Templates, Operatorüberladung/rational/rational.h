#include <iostream>

class rational
{
private:
  int zaehler;
  int nenner;

public:
  rational(int zaehler, int nenner);

  // option 1 & 3
  // friend rational operator*(rational l, rational r);

  // option 2
  rational operator*(rational r);

  friend std::ostream &operator<<(std::ostream &out, rational r);
};