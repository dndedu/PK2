#ifndef PUNKT_H_
#define PUNKT_H_
#include <string>

class Punkt{
    private:
      int x;
      int y;
    public:
      Punkt();
      Punkt(int x, int y);
      Punkt(const Punkt& orig);
      ~Punkt();
      int getX();
      int getY();
      std::string to_string();
};

#endif