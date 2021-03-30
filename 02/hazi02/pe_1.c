#include <stdio.h>

int main()
{
    /*
        Állapítsuk meg azon 1000-nél kisebb számok összegét, melyek 3-nak vagy 5-nek a többszörösei.
    */
    
    printf("1000-nél kisebb pozitív egész számok összege:\n");
    int osszeg = 0;
    
    for (int i = 0; i < 1000; i++)
    {
        if (i % 3 == 0)
        {
            osszeg = osszeg + i;
        }
        else if (i % 5 ==0)
        {
            osszeg = osszeg + i;
        } 
    }
    
    printf("%d\n", osszeg);
    
    return 0;
}