#include <stdio.h>

void podwojWartosc(float *wskaznik) {
    *wskaznik *= 2;
}

int main() {
    float a = 5.0f;
    printf("Zmienna: %.1f\n", a);
    podwojWartosc(&a);
    printf("Nowa wartosc zmiennej: %.1f\n", a);
    return 0;
}
