#ifndef STACK_H_
#define STACK_H_
#include <iostream>
#include <vector>

class Stack
{
private:
  struct element
  {
    long key;
    element *next;

    element(long key, element *next) : key{key}, next{next} {}
    // Wird hier nicht benoetigt. Dient nur der Veranschaulichung.
    ~element()
    {
      std::cout << "Destruktor" << std::endl;
    }
  };
  element *top;

public:
  Stack();
  Stack(const Stack &other);
  ~Stack();
  int push(long key);
  long pop();
};
#endif