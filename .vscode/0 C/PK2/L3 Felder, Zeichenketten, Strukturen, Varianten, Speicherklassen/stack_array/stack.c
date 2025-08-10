#define MAX 100

long stack[MAX];
int top = -1;

int push(long key)
{
    if (top < MAX - 1)
    {
        stack[++top] = key;
        return 1;
    }
    else
    {
        return 0;
    }
}

// Achtung: Key -1 kann nicht gespeichert werden
long pop()
{
    if (top > -1)
    {
        return stack[top--];
    }
    else
    {
        return -1;
    }
}