#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int wiersze, kolumny;
    printf("Podaj liczbe wierszy: ");
    scanf("%d", &wiersze);
    printf("Podaj liczbe kolumn: ");
    scanf("%d", &kolumny);

    srand(time(NULL));

    int **macierz = (int **)malloc(wiersze * sizeof(int *));
    for (int i = 0; i < wiersze; i++) 
    {
        macierz[i] = (int *)malloc(kolumny * sizeof(int));
    }

    printf("Zawartosc macierzy:\n");
    for (int i = 0; i < wiersze; i++) 
    {
        for (int j = 0; j < kolumny; j++) 
        {
            macierz[i][j] = rand() % 100;
            printf("%d\t", macierz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < wiersze; i++) 
    {
        free(macierz[i]);
    }
    free(macierz);

    return 0;
}
