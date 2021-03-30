#include <stdio.h>

int contains(const int n, const int tomb[], const int keresett)
{
    for (int i = 0; i < n; i++)
    {
        if (tomb[i] == keresett)
        {
            return 1;           //igaz
        }
        
    }
    
    return 0;                   //hamis
}

int main()
{
    int t1[5] = { 1, 2, 3, 2, 1 };
    int t1_meret = 5;
    int keresett = 3;
    
    int benne_van = contains(t1_meret, t1, keresett);
    printf("Benne van %d? %s\n", keresett, benne_van ? "igen" : "nem");

    return 0;
}