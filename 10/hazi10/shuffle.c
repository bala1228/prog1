#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fisher–Yates keverés algoritmus
void shuffle(int n, int tomb[])
{
    int temp = 0;
    
    for (int i = n - 1; i > 0; i--)
    {
        // Random index
        int j = rand() % i;
        // számok keverése
        temp = tomb[i];
        tomb[i] = tomb[j];
        tomb[j] = temp;
    }
}

int main()
{
    int tomb[] = { 1, 2, 3, 4, 5, 6 };
    int tomb_hossz = 6;


    for (int i = 0; i < 6; i++)
    {
        printf("%d ", tomb[i]);
    }
    puts("");

    shuffle(tomb_hossz, tomb);

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", tomb[i]);
    }
    puts("");

    return 0;
}