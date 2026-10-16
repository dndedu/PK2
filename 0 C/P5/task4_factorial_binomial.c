unsigned long fakultaet(int natuerlicheZahl)
{
    if (natuerlicheZahl == 0)
    {
        return 1;
    }

    unsigned long result = 1;
    for (int k = 1; k <= natuerlicheZahl; k++)
    {
        result *= k;
    }

    return result;
}

// Berechnung des Binomialkoeffizienten "natuerlicheZahl über k", C(natuerlicheZahl,k) = natuerlicheZahl! / (k! * (natuerlicheZahl-k)!)
unsigned long binomialkoeffizient(int natuerlicheZahl, int k)
{
    if (k < 0 || k > natuerlicheZahl || natuerlicheZahl < 0)
    {
        return 0;
    }

    // // Variante 1
    // unsigned long natuerlicheZahl_fakultaet = fakultaet(natuerlicheZahl);                                 // n!
    // unsigned long k_fakultaet = fakultaet(k);                                                             // k!
    // unsigned long natuerlicheZahl_minus_k_fakultaet = fakultaet(natuerlicheZahl - k);                     // (n-k)!
    // unsigned long result = natuerlicheZahl_fakultaet / (k_fakultaet * natuerlicheZahl_minus_k_fakultaet); // C(n,k) = n! / (k! * (n-k)!)

    // Variante 2
    // Nutzung von Symmetrie: C(natuerlicheZahl,k) = C(natuerlicheZahl,natuerlicheZahl-k)
    // Wähle kleineren Wert für effizientere Berechnung
    if (k > natuerlicheZahl - k)
    {
        k = natuerlicheZahl - k;
    }
    // Alternative effizientere Berechnung um Overflow zu vermeiden:
    // Kürze (n-k)! aus n! heraus
    // C(n,k) = (n × (n-1) × (n-2) × ... × (n-k+1)) / (k × (k-1) × (k-2) × ... × 1)
    unsigned long result = 1;
    for (int i = 0; i < k; i++)
    {
        result = result * (natuerlicheZahl - i) / (i + 1);
    }

    return result;
}