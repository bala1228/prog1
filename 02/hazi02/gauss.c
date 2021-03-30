#include <stdio.h>

int main()
{
    /*
        Írjunk programot, ami kiszámolja az egész számok összegét 1-től 100-ig.
    */
    
    int osszeg = 0;

    printf("Egész számok összege 1-100-ig:\n");
    
    for (int i = 0; i <= 100; i++)
    {
        osszeg = osszeg + i;
    }
      
    printf("%d\n", osszeg);
    
    return 0;
}
