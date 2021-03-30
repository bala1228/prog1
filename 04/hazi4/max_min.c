#include <stdio.h>

int max(const int n, const int tomb[])
{
    int result = tomb[0];

    for (int i = 1; i < n; i++)
    {
        if (tomb[i] > result)
        {
            result = tomb[i];
        }
    }
    
    return result;
}

int min(const int n, const int tomb[])
{
    int result = tomb[0];

    for (int i = 1; i < n; i++)
    {
        if (tomb[i] < result)
        {
            result = tomb[i];
        }
    }
    
    return result;
}

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
    int szamok[10] = { 156, 455, 4, -54, 489, 55555 , 9, 32, 5, -5667 };
    //int szamok[10] = { 1, 55, -483, 4, 89, 5 , 958, 2, -78, 67 };
    int meret = 10;

    tomb_kiir(meret, szamok);

    printf("Legnagyobb: %d\n", max(meret, szamok));
    printf("Legkisebb: %d\n", min(meret, szamok));

    return 0;
}
