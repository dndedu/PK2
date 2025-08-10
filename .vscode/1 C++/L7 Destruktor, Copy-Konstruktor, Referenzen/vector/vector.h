class Vector
{
private:
  int size;
  double *feld;

public:
  Vector(int size);
  Vector(const Vector &orig);
  ~Vector();
  void set(int index, double value);
  double get(int index);
};