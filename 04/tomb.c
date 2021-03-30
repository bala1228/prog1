#include <stdio.h>

void tomb_kiir(int m, const int tomb[])
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ", tomb[i]);
    }
    puts(" ");      //printf("\n");
}

int main()
{
    int szamok[10] = { 156, 455, 4, 54, 489, 9 , 9, 32, 5, 5667 };
    int meret = 10;

    printf("Előtte: %d\n", szamok[0]);
    tomb_kiir(meret, szamok);
    printf("Utána: %d\n", szamok[0]);

    return 0;
}