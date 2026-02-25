#include <stdio.h>

// Das Makro erstellt lokale Kopien (_a, _b), damit x++ nur einmal ausgeführt wird.
#define MIN(a, b) ({ \
    __typeof__( (a) + 0 ) _a = (a); \
    __typeof__( (b) + 0 ) _b = (b); \
    _a < _b ? _a : _b; \
})

int main() {
    int x = 2;
    int y = 3;

    // x++ wird hier nur einmal bei der Zuweisung zu _a ausgeführt
    int result = MIN(x++, y); 

    printf("Ergebnis: %d\n", result); // Erwartet: 2
    printf("x nachher: %d\n", x);    // Erwartet: 3
    
    return 0;
}

//Execute with
//gcc -E test_gnu_macro.c | grep -A 5 "main"

//show code in file after preprocessor
//gcc -E test_gnu_macro.c > preprocessed.c

// Das "Automatische Löschen" (One-Liner)
// gcc -E test_gnu_macro.c > temp.c && code --wait temp.c && rm temp.c
    // Was passiert hier?
    // gcc -E ... > temp.c: Erzeugt die temporäre Datei.
    // && code --wait temp.c: Öffnet die Datei in VS Code (der Befehl code startet VS Code). Das --wait ist wichtig: Die Konsole pausiert so lange, bis du den Tab der Datei in VS Code wieder schließt.
    // && rm temp.c: Erst wenn du fertig bist und den Tab schließt, wird die Datei automatisch gelöscht.

// Die "Direkte Optimierung" (Compiler-Magie)
//     static inline int safe_min(int a, int b) {
//         return a < b ? a : b;
//     }
//     ...kannst du den GCC anweisen, diese Funktion so zu behandeln, als wäre sie ein Makro (also den Code direkt an die Stelle des Aufrufs zu kopieren), aber ohne die x++ Fehler.
// gcc -O2 test_gnu_macro.c -o test_prog
//     Was bewirkt -O2?
//     Inlining: Der Compiler sieht deine static inline Funktion. Er merkt: "Oh, die ist klein und wird oft aufgerufen." Er kopiert den Maschinen-Code der Funktion direkt in die main, genau wie ein Makro.
//     Safety: Da es aber technisch eine Funktion bleibt, sorgt der Compiler dafür, dass x++ zuerst berechnet wird und nur der fertige Wert (die 2) in den Vergleich einfließt.
//     Speed: Das Ergebnis ist exakt so schnell wie ein Makro, aber 100% sicher.