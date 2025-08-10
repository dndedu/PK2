int count_space_withIndex(char s[])
{
    int count = 0;

    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            count++;
        }
        i++;
    }

    return count;
}

int count_space_withPointer(char s[])
{
    int count = 0;

    char *ptr = s;
    while (*ptr != '\0')
    {
        if (*ptr == ' ')
        {
            count++;
        }
        ptr++;
    }

    return count;
}