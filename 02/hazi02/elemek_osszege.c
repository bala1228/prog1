#include <stdio.h>

int main()
{
    /*
        Írjon programot, ami 0 végjelig egész számokat olvas be. 
        Írja ki a számok összegét (a végjel természetesen nem 
        számít).
    */
    int szam;
    int osszeg = 0;
    
    do
    {
        printf("Egesz szam (vege: 0): ");
        scanf("%d", &szam);
        osszeg = osszeg + szam;
    } while (szam != 0);

    printf("\n");
    printf("Elemek osszege: %d\n", osszeg);
        
    return 0;
}
