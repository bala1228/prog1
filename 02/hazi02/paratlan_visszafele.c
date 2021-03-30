#include <stdio.h>

int main()
{
    /*
        Írjunk egy programot, amely beolvas egy pozitív egész számot (n), 
        majd kiírja n-től 1-ig (zárt intervallum) visszafelé az összes páratlan számot!
    */    
    
    int n;
    printf("n: ");
    scanf("%d", &n);
    printf("\n");

    for (int i = n; i >= 1; i--)
    {
        if (i % 2 == 1)
        {
            printf("%d\n", i);
        } 
    }
    
    return 0;
}