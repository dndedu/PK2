#include <stdio.h>
#define LENGTH 2

int queue[LENGTH];
int currentPosition = -1, longestTime = -1, currentLength = 0;

void enqueue(int i)
{
    if (currentLength < LENGTH)
        currentLength++;

    if (currentPosition == -1)
    {
        currentPosition = longestTime = 0;
        queue[currentPosition] = i;
    }
    else if ((currentPosition + 1) % LENGTH == longestTime)
    {
        queue[currentPosition] = i;
    }
    else
    {
        currentPosition = (currentPosition + 1) % LENGTH;
        queue[currentPosition] = i;
    }
}

int dequeue()
{
    if (longestTime != -1)
    {
        int tmp = queue[longestTime];
        longestTime = (longestTime + 1) % LENGTH;
        currentLength--;
        if (currentLength == 0)
            currentPosition = longestTime = -1;
        return tmp;
    }
    return -1;
}