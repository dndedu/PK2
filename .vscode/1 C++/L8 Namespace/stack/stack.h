namespace pk2
{
  class stack
  {
  private:
    struct element
    {
      long key;
      element *next;

      element(long key, element *next) : key{key}, next{next} {}
    };

    element *top = nullptr;

  public:
    stack();
    ~stack();
    stack(const stack &orig);
    int push(long);
    long pop();
  };
}