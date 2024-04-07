#include <stdio.h>

// Funkcja rekurencyjna do wyszukiwania binarnego
int wyszukiwanie(int tab[], int lewy, int prawy, int szukany) {
    if (prawy >= lewy) 
    {
        int srodek = lewy + (prawy - lewy) / 2;
        if (tab[srodek] == szukany)     return srodek;
        if (tab[srodek] > szukany)      return wyszukiwanie(tab, lewy, srodek - 1, szukany);
        return wyszukiwanie(tab, srodek + 1, prawy, szukany);
    }
    return -1;
}

int main() {
    int tab[] = {1,4,8,12,14,18,20,25,30};
    int n = sizeof(tab) / sizeof(tab[0]);
    int szukany = 14;
    int wynik = wyszukiwanie(tab, 0, n - 1, szukany);
    if (wynik == -1) 
    {
        printf("Element nie został znaleziony w tablicy.\n");
    } else 
    {
        printf("Element znaleziony na indeksie: %d.\n", wynik);
    }
    return 0;
}
