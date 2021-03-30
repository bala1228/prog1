#include <stdio.h>

void formazas(const int n, const int tomb[])
{
    for (int i = 0; i < n - 1; i++)
    {
        //n-1 elem kiírása
        printf("%d, ", tomb[i]);
    }
    //n-edik elem kiírása
    printf("%d\n", tomb[n-1]);
}

int main()
{
    int tomb[5] = { 1, 2, 3, 4, 5 };
    int tomb_meret = 5;

    formazas(tomb_meret, tomb);

    return 0;
}