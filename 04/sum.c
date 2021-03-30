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

int main()
{
    int szamok[10] = { 156, 455, 4, 54, 489, 9 , 9, 32, 5, 5667 };
    int meret = 10;

    int osszeg = sum(meret , szamok);

    printf("Tömbben lévő számok összege: %d.\n", osszeg);

    return 0;
}