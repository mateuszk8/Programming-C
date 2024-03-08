#include <stdio.h>

int suma(int n) {
    if (n < 0) 
    {
        return 0;
    }
    int sum = 0;
    for (int i = 3; i < n; i++) 
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i; 
        }
    }
    return sum;
}

int main() {
    int number;
    printf("Podaj liczbę: ");
    scanf("%d", &number); 
    printf("Suma wszystkich wielokrotności 3 lub 5 poniżej %d wynosi %d\n", number, suma(number));
    return 0;
}
