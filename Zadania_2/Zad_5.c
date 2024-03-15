#include <stdio.h>
#include <string.h>

#define kontaktyMax 50
#define daneMax 30

struct Contact
{
    char imie[daneMax];
    char nazwisko[daneMax];
    char numer[daneMax];
};

struct Contact kontakty[kontaktyMax];
int rozmiar = 0;

void dodajKontakt(const char* imie, const char* nazwisko, const char* numer) 
{
    if (rozmiar < kontaktyMax) 
    {
        strcpy(kontakty[rozmiar].imie, imie);
        strcpy(kontakty[rozmiar].nazwisko, nazwisko);
        strcpy(kontakty[rozmiar].numer, numer);
        rozmiar++;
    } else 
    {
        printf("Książka adresowa jest pełna.\n");
    }
}

void wyszukajKontakt(const char* nazwisko) 
{
    for (int i = 0; i < rozmiar; i++) 
    {
        if (strcmp(kontakty[i].nazwisko, nazwisko) == 0) 
        {
            printf("Kontakt znaleziony: %s %s, %s\n", kontakty[i].imie, kontakty[i].nazwisko, kontakty[i].numer);
            return;
        }
    }
    printf("Kontakt nie znaleziony.\n");
}

void usunKontakt(const char* nazwisko) 
{
    for (int i = 0; i < rozmiar; i++) 
    {
        if (strcmp(kontakty[i].nazwisko, nazwisko) == 0) 
        {
            for (int j = i; j < rozmiar - 1; j++) 
            {
                kontakty[j] = kontakty[j + 1];
            }
            rozmiar--;
            return;
        }
    }
    printf("Contact not found.\n");
}

void pokazKontakty() 
{
    for (int i = 0; i < rozmiar; i++) 
    {
        printf("Kontakt %d: %s %s, %s\n", i+1, kontakty[i].imie, kontakty[i].nazwisko, kontakty[i].numer);
    }
}

int main() {
    int wybor;
    char imie[daneMax], nazwisko[daneMax], numer[daneMax];

    while (1) {
    printf("\n1. Dodaj kontakt\n2. Wyszukaj kontakt\n3. Usuń kontakt\n4. Pokaż kontakty\n5. Zamknij\nWybierz opcję: ");
    scanf("%d", &wybor);

    switch (wybor) {
        case 1:
            printf("Podaj imie: ");
            scanf("%s", imie);
            printf("Podaj nazwisko: ");
            scanf("%s", nazwisko);
            printf("Podaj numer: ");
            scanf("%s", numer);
            dodajKontakt(imie, nazwisko, numer);
            break;
        case 2:
            printf("Podaj nazwisko do znalezienia: ");
            scanf("%s", nazwisko);
            wyszukajKontakt(nazwisko);
            break;
        case 3:
            printf("Podaj nazwisko kontaktu do usunięcia: ");
            scanf("%s", nazwisko);
            usunKontakt(nazwisko);
            printf("Kontakt usunięty.\n");
            break;
        case 4:
            pokazKontakty();
            break;
        case 5:
            printf("Program zamknięty.\n");
            return 0;
        default:
            printf("Błąd, spróbuj ponownie.\n");
    }
    }
    return 0;
}
