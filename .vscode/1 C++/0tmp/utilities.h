// C
int sum(int a, int b);
void printString(char string[]);
void string_copy(char *duplikat, const char *original);
void print_mainArguments(int argc, const char *argv[]);

// C++
class Utilities
{
private:
    int hlp_int;
    double hlp_double;

public:
    Utilities();
    Utilities(int hlp_i, double hlp_d) : hlp_int(hlp_i), hlp_double(hlp_d){}; // Inline

    int getHlpInt() const { return hlp_int; }       // Inline
    int getHlpDouble() const { return hlp_double; } // Inline
    void setHlpInt(int i);
    void setHlpDouble(double d);
};