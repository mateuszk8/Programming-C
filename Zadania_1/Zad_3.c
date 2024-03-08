#include <stdio.h>
 
int silnia(int n) {
    if (n == 0)
        return 1;
    else
        return n * silnia(n - 1);
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        printf("Silnia z %d wynosi: %d \n", numbers[i], silnia(numbers[i]));
    }
    return 0;
}
