template <typename T>
class stack
{
private:
    struct element
    {
        T key;
        element *next;

        element(T key, element *next) : key{key}, next{next} {}
    };

    element *top = nullptr;
    T emptystackvalue;

public:
    stack(T esv);
    ~stack();
    stack(const stack &orig);
    int push(T key);
    T pop();
};

template <typename T>
stack<T>::stack(T esv) : emptystackvalue{esv}, top{nullptr} {}

template <typename T>
stack<T>::stack(const stack &orig) : stack{orig.emptystackvalue}
{
    stack<T> tmp{orig.emptystackvalue};

    element *ptr = orig.top;
    while (ptr != nullptr)
    {
        tmp.push(ptr->key);
        ptr = ptr->next;
    }
    T k;
    while ((k = tmp.pop()) != -1)
    {
        this->push(k);
    }
}

template <typename T>
stack<T>::~stack()
{
    while (pop() != emptystackvalue)
        ;
}

template <typename T>
int stack<T>::push(T key)
{
    element *neu = new element{key, top};
    if (neu != nullptr)
    {
        top = neu;
        return 1;
    }
    return 0;
}

template <typename T>
T stack<T>::pop()
{
    if (top != nullptr)
    {
        T k = top->key;
        element *temp = top;
        top = top->next;
        delete temp;
        return k;
    }
    return emptystackvalue;
}