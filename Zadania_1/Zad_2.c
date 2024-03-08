#include <stdio.h>

int main() {

    int grades[2][5] = 
    {
        {5, 4, 3, 2, 1},
        {5, 4, 5, 3, 2}
    };

    double sum_math = 0;
    double sum_physics = 0;

    for (int i = 0; i < 5; i++) 
    { 
        sum_math += grades[0][i];
        sum_physics += grades[1][i];
    }

    double average_math = sum_math / 5;
    double average_physics = sum_physics / 5;

    printf("Średnia ocen z matematyki: %.2f\n", average_math);
    printf("Średnia ocen z fizyki: %.2f\n", average_physics);

    return 0;
}
