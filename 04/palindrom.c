#include <stdio.h>

void tomb_kiir(int m, const int tomb[])
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ", tomb[i]);
    }
    puts(" ");      //printf("\n");
}

int is_palindrome(const int n, const int tomb[])
{
    int i = 0, j = n - 1;

    while (i < j)
    {
        if (tomb[i] != tomb[j])
        {
            return 0;       //hamis
            i++;
            j--;
        }
        else
        {
            break;
        }
    }
    
    return 1;               //igaz
}

int main()
{
    int t1[5] = { 1, 2, 3, 2, 1 };
    int t1_meret = 5;

    int t2[6] = { 1, 2, 3, 3, 2, 1 };
    int t2_meret = 6;

    puts("A t1 tömb elemei:");
    tomb_kiir(t1_meret, t1);

    int eredmeny = is_palindrome(t1_meret, t1);
    printf("A t1 tömb palindróm? %d\n", eredmeny);

    puts("---------------------------------------------------------------------------------------------");

    puts("A t2 tömb elemei:");
    tomb_kiir(t2_meret, t2);
    eredmeny = is_palindrome(t2_meret, t2);
    printf("A t2 tömb palindróm? %d\n", eredmeny);
    
    return 0;
}