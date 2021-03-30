#include <stdio.h>
#include <stdlib.h>

void tomb_kiir(int m, const int tomb[])
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ", tomb[i]);
    }
    puts(" ");      //printf("\n");
}

void pozitiv_hozzaallas(const int meret, int tomb[])
{
    for (int i = 0; i < meret; i++)
    {
        if (tomb[i] < 0)
        {
            tomb[i] = abs(tomb[i]);
        }
    }
}

int main()
{
    int szamok[10] = { 156, 455, 4, -54, 489, 55555 , 9, 32, 5, -5667 };
    //int szamok[10] = { 1, 55, -483, 4, 89, 5 , 958, 2, -78, 67 };
    int meret = 10;

    puts("Előtte:");
    tomb_kiir(meret, szamok);

    pozitiv_hozzaallas(meret, szamok);

    puts("Utána:");
    tomb_kiir(meret, szamok);

    return 0;
}
