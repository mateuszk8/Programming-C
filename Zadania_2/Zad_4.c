#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student 
{
    char imie[30];
    float ocena;
};

void sortowanie(struct Student* studenci, int rozmiar) 
{
    for (int i = 0; i < rozmiar - 1; i++) 
    {
        for (int j = 0; j < rozmiar - i - 1; j++) 
        {
            if (studenci[j].ocena < studenci[j + 1].ocena) 
            {
                struct Student X = studenci[j];
                studenci[j] = studenci[j + 1];
                studenci[j + 1] = X;
            }
        }
    }
}

int main() {
    struct Student studenci[100];
    for(int i = 0; i < 100; i++)        // Przykładowe dane
    {      
        sprintf(studenci[i].imie, "Student nr: %d", i + 1);
        studenci[i].ocena = 2.0 + (float)(rand() % 31) / 10.0;  // Losowe oceny od 2.0 do 5.0
    }
    sortowanie(studenci, 100);
    for (int i = 0; i < 100; i++)       // Wypisanie posortowanej listy studentów
    { 
        printf("%s: %.2f\n", studenci[i].imie, studenci[i].ocena);
    }
    return 0;
}
