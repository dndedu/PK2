#include <stdlib.h>
#include <stdio.h>

struct element
{
    long key;
    struct element *next;
};

struct element *top = NULL;

int push(long k)
{
    struct element *neu = (struct element *)malloc(sizeof(struct element));
    if (neu != NULL)
    {
        neu->key = k;
        neu->next = top;
        top = neu;
        return 1;
    }
    else
    {
        return 0;
    }
}

long pop()
{
    if (top != NULL)
    {
        long k = top->key;
        struct element *tmp = top;
        top = top->next;
        free(tmp);
        return k;
    }
    else
    {
        return -1;
    }
}

int main()
{
    long i;
    for (i = 1; i <= 100; i++)
    {
        push(i);
    }

    while ((i = pop()) != -1)
    {
        printf("%ld\n", i);
    }

    return 0;
}