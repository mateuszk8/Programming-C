#include <stdio.h>

void zamiana(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void wyswietlanie(int* tab, int size) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

void permute(int* tab, int poczatek, int koniec) 
{
    if (poczatek == koniec) 
    {
        wyswietlanie(tab, koniec + 1);
    } else 
    {
        for (int i = poczatek; i <= koniec; i++) 
        {
            zamiana((tab + poczatek), (tab + i));
            permute(tab, poczatek + 1, koniec);
            zamiana((tab + poczatek), (tab + i));
        }
    }
}

int main() {
    int tab[] = {1, 2, 3};
    int n = sizeof(tab) / sizeof(tab[0]);
    permute(tab, 0, n - 1);
    return 0;
}
