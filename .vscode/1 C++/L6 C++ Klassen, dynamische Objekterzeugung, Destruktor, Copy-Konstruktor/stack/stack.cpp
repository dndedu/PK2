#include "stack.h"

Stack::Stack() : top{nullptr}
{
}

// // copy constructor with indirect copy via temporary stack
// Stack::Stack(const Stack &other) : top{nullptr}
// {
//     if (other.top == nullptr)
//         return;

//     // Copy elements in reverse order to maintain stack order
//     Stack temp;
//     element *current = other.top;
//     while (current != nullptr)
//     {
//         temp.push(current->key);
//         current = current->next;
//     }

//     // Now copy from temp to this stack
//     while (temp.top != nullptr)
//     {
//         push(temp.top->key);
//         temp.top = temp.top->next; // Manual cleanup to avoid double deletion
//     }
// }

// goto solution: naturally exception-safe solution
Stack::Stack(const Stack &other) : top{nullptr}
{
    if (other.top == nullptr)
        return;

    // First pass: collect all keys using a temporary stack
    Stack temp;
    element *current = other.top;
    while (current != nullptr)
    {
        temp.push(current->key); // This reverses the order
        current = current->next;
    }

    // Second pass: pop from temp and push to this (reverses back to correct order)
    long value;
    while ((value = temp.pop()) != -1)
    {                // pop() properly deletes each element
        push(value); // Add to the new stack
    }
    // temp's destructor will run automatically and clean up any remaining elements
}

// // copy constructor with one direct copy (faster than copying content on temporary stack)
// Stack::Stack(const Stack &other) : top{nullptr}
// {
//     if (other.top == nullptr)
//         return;

//     // Copy elements directly
//     element *current = other.top;
//     element *prev = nullptr;

//     while (current != nullptr)
//     {
//         element *newElem = new element{current->key, nullptr};
//         if (prev == nullptr)
//         {
//             top = newElem; // First element
//         }
//         else
//         {
//             prev->next = newElem;
//         }
//         prev = newElem;
//         current = current->next;
//     }
// }

// // no manual memory management needed; automatic cleanup
// Stack::Stack(const Stack &other) : top{nullptr}
// {
//     if (other.top == nullptr)
//         return;

//     // Collect values in correct order
//     std::vector<long> values;
//     element *current = other.top;
//     while (current != nullptr)
//     {
//         values.push_back(current->key);
//         current = current->next;
//     }

//     // Push in reverse order to maintain stack order
//     for (int i = values.size() - 1; i >= 0; i--)
//     {
//         push(values[i]);
//     }
// }

// //RAiI, Resource Aquisition is Initialization
// Stack::Stack(const Stack& other) : top{nullptr} {
//     if (other.top == nullptr) return;

//     try {
//         element* current = other.top;
//         element* prev = nullptr;

//         while (current != nullptr) {
//             element* newElem = new element{current->key, nullptr};
//             if (prev == nullptr) {
//                 top = newElem;
//             } else {
//                 prev->next = newElem;
//             }
//             prev = newElem;
//             current = current->next;
//         }
//     } catch (...) {
//         // Clean up any partially constructed chain
//         while (top != nullptr) {
//             element* temp = top;
//             top = top->next;
//             delete temp;
//         }
//         throw;  // Re-throw the exception
//     }
// }

Stack::~Stack()
{
    while (pop() != -1)
        ;
}

int Stack::push(long k)
{
    element *neu = new element{k, top};
    if (neu != nullptr)
    {
        std::cout << "Pushed: " << k << std::endl;
        top = neu;
        return 1;
    }
    else
    {
        return 0;
    }
}

long Stack::pop()
{
    if (top != nullptr)
    {
        long k = top->key;
        element *tmp = top;
        top = top->next;
        delete tmp; // Destruktor
        return k;
    }
    else
    {
        return -1;
    }
}