#include <stdio.h>

void tomb_kiir(int m, const int tomb[])
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ", tomb[i]);
    }
    puts(" ");      //printf("\n");
}

void reverse(int n, int tomb[])
{
    int i = 0, j = n - 1, tmp;

    while (i < j)
    {
        //csere
        tmp = tomb[i];
        tomb[i] = tomb[j];
        tomb[j] = tmp;
        i++;
        j--;
    }
    
}

int main()
{
    int szamok[10] = { 156, 455, 4, 54, 489, 9 , 9, 32, 5, 5667 };
    int meret = 10;

    puts("előtte:");
    tomb_kiir(meret, szamok);

    reverse(meret, szamok);

    puts("utána:");
    tomb_kiir(meret, szamok);

    return 0;
}