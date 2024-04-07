#include <stdio.h>

int factorial(int x) 
{
    if (x == 0) 
    {
        return 1;
    } else 
    {
        return x * factorial(x - 1);
    }
}

int main() {
    int x;
    printf("Podaj liczbe do obliczenia silni: ");
    scanf("%d", &x);
    printf("Silnia z %d wynosi %lld.\n", x, factorial(x));
    return 0;
}
