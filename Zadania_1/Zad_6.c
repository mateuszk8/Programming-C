#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

int ruchKomputera() // Losowanie liczby od 0 do 2 gdzie 0 to kamień, 1 to papier, 2 to nożyce
{
    return rand() % 3;
}

char* zamiana(int X) //Zmiana wylosowanej liczby na słowo
{ 
    switch(X) 
    {
        case 0: return "kamień";
        case 1: return "papier";
        case 2: return "nożyce";
    }
}

int wynikParti(int wyborGracza, int wyborKomputera) // Zwraca 0 jeśli remis, 1 jeśli gracz wygrał, 2 jeśli komputer wygrał
{
    if(wyborGracza == wyborKomputera) return 0;
    if((wyborGracza == 0 && wyborKomputera == 2) || 
       (wyborGracza == 1 && wyborKomputera == 0) || 
       (wyborGracza == 2 && wyborKomputera == 1)) return 1;
    return 2;
}

int main() {
    int wyborGracza, wyborKomputera, wynik;
    int runda = 0;
    int scores[100][3]; // tablica z wynikami
    char ruch[10];

    srand(time(NULL)); // Inicjalizacja generatora liczb pseudolosowych

    while(1) 
    {
        printf("Wybierz: 0 - kamień, 1 - papier, 2 - nożyce, lub wpisz 'scores' aby zobaczyć wyniki: ");
        scanf("%s", ruch);

        if(strcmp(ruch, "scores") == 0) 
        {
            printf("Wyniki dotychczasowych rund:\n");
            for(int i = 0; i < runda; i++) 
            {
                printf("Runda %d: gracz - %s, komputer - %s, %s\n",
                i + 1, 
                zamiana(scores[i][0]), 
                zamiana(scores[i][1]), 
                scores[i][2] == 0 ? "remis" : scores[i][2] == 1 ? "gracz wygrał" : "komputer wygrał");
            }
            continue;
        }

        wyborGracza = atoi(ruch); // zamiana na liczbę
        wyborKomputera = ruchKomputera();
        wynik = wynikParti(wyborGracza, wyborKomputera);

        // Zapisz wyniki rundy
        scores[runda][0] = wyborGracza;
        scores[runda][1] = wyborKomputera;
        scores[runda][2] = wynik;
        runda++;

        // Wyświetl wyniki rundy
        printf("Wybrałeś %s, komputer wybrał %s. %s!\n",zamiana(wyborGracza),zamiana(wyborKomputera), 
               wynik == 0 ? "Remis" : wynik == 1 ? "Wygrałeś" : "Komputer wygrał");

        if(runda >= 100) 
        {
            printf("Osiągnięto maksymalną liczbę rund.\n");
            break;
        }
    }

    return 0;
}
