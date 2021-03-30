#include <stdio.h>

int index_kereso(const int n, const int tomb[], const int keresett)
{
    for (int i = 0; i < n; i++)
    {
        if (tomb[i] == keresett)
        {
            return i;           //igaz
        }
    }
    
    return -1;                   //hamis
}

int main()
{
    int t1[5] = { 1, 2, 3, 2, 1 };
    int t1_meret = 5;
    int keresett = 5;
    
    printf("Melyik indexen van %d? %d\n", keresett, index_kereso(t1_meret, t1, keresett));

    return 0;
}
