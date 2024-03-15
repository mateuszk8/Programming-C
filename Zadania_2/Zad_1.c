#include <stdio.h>

int main() {
    int zmienna = 10;
    int *wskaznik = &zmienna;
    *wskaznik = 25;
    printf("Wartość zmiennej (bezpośrednio): %d\n", zmienna);
    printf("Wartość zmiennej (przez wskaźnik): %d\n", *wskaznik);
    return 0;
}
