#include <stdio.h>
#include "char_utility.h"
#include "queue.h"

int main()
{
    char text[] = "Hi! My name is Daniel!";
    printf("Text: %s\n", text);
    upper(text);
    printf("Text in upper case: %s\n", text);

    enqueue(1);
    enqueue(2);
    enqueue(2);
    printf("%i ", dequeue());
    enqueue(3);
    printf("%i ", dequeue());
    printf("%i ", dequeue());
    printf("%i ", dequeue());
    enqueue(4);
    enqueue(5);
    printf("%i ", dequeue());
    printf("%i \n", dequeue());

    return 0;
}