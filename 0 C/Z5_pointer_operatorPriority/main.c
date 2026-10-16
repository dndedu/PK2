#include <stdio.h>

struct Person
{
    char name[20];
    int age;
};

int main()
{
    struct Person person = {"Alice", 25};
    struct Person *ptr = &person;
    struct Person **double_ptr = &ptr;

    printf("=== Operator-Priorität Demo ===\n");
    printf("person.name = %s\n", person.name);
    printf("ptr->name = %s\n", ptr->name);
    printf("(*double_ptr)->name = %s\n", (*double_ptr)->name);

    printf("\n=== Was NICHT funktioniert ===\n");
    // 1. double_ptr->name würde Compiler-Fehler geben:
    // printf("%s\n", double_ptr->name);  // FEHLER!
    printf("double_ptr->name würde Compiler-Fehler geben: 'struct Person *' hat kein 'name' Feld\n");

    // 2. *double_ptr->name wäre *(double_ptr->name), würde also auch Compiler-Fehler geben:
    // printf("%s\n", *double_ptr->name);  // FEHLER!
    printf("*double_ptr->name wäre *(double_ptr->name), würde Compiler-Fehler geben, double_ptr hat kein 'name' Feld\n");

    printf("\n=== Operator-Prioritäten ===\n");
    printf("-> und . haben höchste Priorität\n");
    printf("* (Dereferenzierung) hat niedrigere Priorität\n");
    printf("Deshalb: *a->b = *(a->b), nicht (*a)->b\n");

    printf("\n=== Korrekte Zugriffe ===\n");
    printf("double_ptr = %p\n", (void *)double_ptr);
    printf("*double_ptr = %p\n", (void *)*double_ptr);
    printf("**double_ptr wäre die Person selbst (aber das macht keinen Sinn für printf)\n");
    printf("(*double_ptr)->name = %s (RICHTIG)\n", (*double_ptr)->name);

    printf("\n=== Äquivalente Schreibweisen ===\n");
    printf("(*double_ptr)->name = %s\n", (*double_ptr)->name);
    printf("(**double_ptr).name = %s\n", (**double_ptr).name);

    return 0;
}