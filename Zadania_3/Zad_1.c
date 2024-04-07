#include <stdio.h>

int silnia(int n) 
{
    int silnia = 1;
    for (int i = 2; i <= n; i++) {
        silnia *= i;
    }
    return silnia;
}

int dwumian(int n, int k) 
{
    return silnia(n) / (silnia(k) * silnia(n - k));
}

void trojkat(int wysokosc) 
{
    for (int i = 0; i < wysokosc; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            printf("%d ", dwumian(i, j));
        }
        printf("\n");
    }
}

int main() {
    int wysokosc;
    printf("Podaj wysokość trójkąta Pascala: ");
    scanf("%d", &wysokosc);
    trojkat(wysokosc);
    return 0;
}
