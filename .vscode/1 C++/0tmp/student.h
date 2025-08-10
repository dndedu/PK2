class Student
{
    // private:
    const char *name;
    int matrikelnummer;

public:
    Student();
    Student(const char *n, int m);
    const char *getName();
    int getMatrikelnr();
    void druckeDaten();
};