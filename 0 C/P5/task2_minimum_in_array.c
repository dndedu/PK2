double min(double a[], int n)
{
    if (n <= 0)
    {
        return 0.0;
    }

    double minimum = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < minimum)
        {
            minimum = a[i];
        }
    }

    return minimum;
}