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
    int szamok[10] = { 156, 455, 4, 54, 489, 55555 , 9, 32, 5, 5667 };
    int meret = 10;

    int legnagyobb = max(meret, szamok);
    printf("Legnagyobb: %d\n", legnagyobb);
    //tomb_kiir(meret, szamok);
    //printf("Utána: %d\n", szamok[0]);

    return 0;
}