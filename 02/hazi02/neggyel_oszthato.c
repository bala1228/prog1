#include <stdio.h>

int main()
{
    /*
        Írjunk egy programot, amely beolvas egy pozitív egész számot (n), 
        majd kiírja 1-től n-ig (zárt intervallum) az összes néggyel osztható számot!
    */    
    
    int n;
    printf("n: ");
    scanf("%d", &n);
    printf("\n");

    for (int i = n; i >= 1; i--)
    {
        if (i % 4 == 0)
        {
            printf("%d\n", i);
        } 
    }
    
    return 0;
}