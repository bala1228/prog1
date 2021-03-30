#include <stdio.h>

int sum(const int n, const int tomb[])
{
    int osszeg = 0;
    for (int i = 0; i < n; i++)
    {
        osszeg += tomb[i];      //osszeg = osszeg + tomb[i];
    }
    
    return osszeg;
}

float average(const int n, const int tomb[])
{
    return sum(n, tomb) / (float)n;
}

int main()
{
    int szamok[10] = { 156, 455, 4, 54, 489, 9 , 9, 32, 5, 5667 };
    int meret = 10;

    float atlag = average(meret , szamok);

    printf("Tömbben lévő számok átlaga: %.2f\n", atlag);

    return 0;
}