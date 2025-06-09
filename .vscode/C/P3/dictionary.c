#include <stdio.h>
#include <stdlib.h>
#define LENGTH_MAX 2

typedef enum status{
    FREE;
    TAKEN; //OCCUPIED
    DELETED;
} status_t;

typedef struct element
{
    int value;
    status_t s = FREE;
};

static element dictionary[LENGTH_MAX];
static int currentLength = 0;

int hash(int v, int multiplier)
{
    return (v + multiplier) % LENGTH_MAX; //linear probing
}

int insert(int v)
{
    if (currentLength < LENGTH_MAX)
    {
        element neu;
        neu.value = v;
        // neu.status_t = FREE;

        int multiplier = 1;
        int pos = hash(v, multiplier);
        while (!(dictionary[pos].status_t == TAKEN))
        {
            multiplier++;
            pos = hash(v, multiplier);
        }
        dictionary[pos] = neu;
        dictionary[pos].status_t = TAKEN;
        currentLength++;
        return 1;
    }
    return 0;
}

int delete(int v)
{
    int deleted = 0;

    int multiplier = 1;
    int pos = hash(v, multiplier);

    while (dictionary[pos].value != v || dictionary[pos].status_t == DELETED)
    {
        multiplier++;
        pos = hash(v, multiplier);
    }
    if (dictionary[pos].value == v)
    {
        deleted = dictionary[pos].deleted = 1;
        currentLength--;
    }
    return deleted;
}

int member(int v)
{
    int multiplier = 1;
    int pos = hash(v, multiplier);
    while (dictionary[pos].value != v || dictionary[pos].deleted)
    // while (dictionary[pos].value != v && !dictionary[pos].deleted)
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
        dictionary[i].deleted = 1;
    }

    printf("%d\n", insert(1));
    printf("%d\n", insert(3));
    printf("%d\n", delete(3));
    printf("%d\n", insert(5));
    printf("%d\n", member(5));

    return 0;
}