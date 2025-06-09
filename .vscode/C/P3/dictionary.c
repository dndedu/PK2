#include <stdio.h>
#include <stdlib.h>
#define LENGTH_MAX 2

typedef enum status
{
    FREE,
    TAKEN, // OCCUPIED
    DELETED
} status_t;

typedef struct element
{
    int value;
    status_t status;
} element_t;

static element_t dictionary[LENGTH_MAX];
static int currentLength = 0;

int hash(int v, int multiplier)
{
    return (v + multiplier) % LENGTH_MAX; // linear probing
}

int insert(int v)
{
    if (currentLength < LENGTH_MAX)
    {
        int multiplier = 1;
        int pos = hash(v, multiplier);
        while (dictionary[pos].status == TAKEN)
        {
            multiplier++;
            pos = hash(v, multiplier);
        }

        element_t neu;
        neu.value = v;
        neu.status = TAKEN;

        dictionary[pos] = neu;
        currentLength++;
        return 1;
    }
    return 0;
}

int delete(int v)
{
    int multiplier = 1;
    int pos = hash(v, multiplier);

    // skipping entries
    while (dictionary[pos].value != v || dictionary[pos].status == DELETED)
    {
        multiplier++;
        pos = hash(v, multiplier);
    }

    if (dictionary[pos].value == v)
    {
        dictionary[pos].status = DELETED;
        currentLength--;
        return 1;
    }

    return 0;
}

int member(int v)
{
    int multiplier = 1;
    int pos = hash(v, multiplier);
    while (dictionary[pos].value != v || dictionary[pos].status == DELETED)
    {
        multiplier++;
        pos = hash(v, multiplier);
    }

    if (dictionary[pos].value == v)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int i;
    for (i = 0; i < LENGTH_MAX; i++)
    {
        dictionary[i].status = FREE;
    }

    printf("%d\n", insert(1));
    printf("%d\n", insert(3));
    printf("%d\n", delete(3));
    printf("%d\n", insert(5));
    printf("%d\n", member(5));

    return 0;
}