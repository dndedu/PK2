#include <stdio.h>

struct Person
{
    char name[20];
    int age;
};

void demonstrate_pointers()
{
    // 1. Normale Variable
    struct Person person1 = {"Alice", 25};
    printf("1. person1.name = %s, person1.age = %d\n", person1.name, person1.age);
    printf("   Adresse von person1: %p\n\n", (void *)&person1);

    // 2. Einfacher Zeiger
    struct Person *ptr = &person1;
    printf("2. ptr zeigt auf person1\n");
    printf("   ptr = %p (Adresse, auf die ptr zeigt)\n", (void *)ptr);
    printf("   ptr->name = %s\n", ptr->name);
    printf("   Adresse von ptr selbst: %p\n\n", (void *)&ptr);

    // 3. Doppelter Zeiger
    struct Person **ptr_ptr = &ptr;
    printf("3. ptr_ptr zeigt auf ptr\n");
    printf("   ptr_ptr = %p (Adresse von ptr)\n", (void *)ptr_ptr);
    printf("   *ptr_ptr = %p (Wert von ptr, also Adresse von person1)\n", (void *)*ptr_ptr);
    printf("   (*ptr_ptr)->name = %s (person1.name über doppelten Zeiger)\n", (*ptr_ptr)->name);
    printf("   Adresse von ptr_ptr selbst: %p\n\n", (void *)&ptr_ptr);

    // 4. Array von Zeigern (wie in unserem Beispiel)
    struct Person person2 = {"Bob", 30};
    struct Person *people[2] = {&person1, &person2};

    printf("4. Array von Zeigern:\n");
    printf("   people[0] = %p (zeigt auf person1)\n", (void *)people[0]);
    printf("   people[1] = %p (zeigt auf person2)\n", (void *)people[1]);
    printf("   &people[0] = %p (Adresse des ersten Zeiger-Elements)\n", (void *)&people[0]);
    printf("   &people[1] = %p (Adresse des zweiten Zeiger-Elements)\n\n", (void *)&people[1]);
}

// Swap-Funktion für Zeiger
void swap_pointers(struct Person **a, struct Person **b)
{
    printf("Vor Swap:\n");
    printf("  *a zeigt auf: %s\n", (*a)->name);
    printf("  *b zeigt auf: %s\n", (*b)->name);

    struct Person *tmp = *a; // tmp = Inhalt von a (also der Zeiger)
    *a = *b;                 // Inhalt von a = Inhalt von b
    *b = tmp;                // Inhalt von b = tmp

    printf("Nach Swap:\n");
    printf("  *a zeigt auf: %s\n", (*a)->name);
    printf("  *b zeigt auf: %s\n", (*b)->name);
}

int main()
{
    demonstrate_pointers();

    // Praktisches Beispiel: Zeiger im Array vertauschen
    struct Person person1 = {"Alice", 25};
    struct Person person2 = {"Bob", 30};
    struct Person *people[2] = {&person1, &person2};

    printf("5. Zeiger-Swap Demonstration:\n");
    printf("Vor Swap: people[0]->name = %s, people[1]->name = %s\n",
           people[0]->name, people[1]->name);

    // Hier passiert die Magie:
    // people[0] ist vom Typ struct Person*
    // &people[0] ist vom Typ struct Person**
    swap_pointers(&people[0], &people[1]);

    printf("Nach Swap: people[0]->name = %s, people[1]->name = %s\n",
           people[0]->name, people[1]->name);

    return 0;
}