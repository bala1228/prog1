#include <stdio.h>

int main()
{
    /*
        Írjon programot, ami 0 végjelig egész számokat olvas be.
        Írja ki, hány darab pozitív számot adott meg a felhasználó (a végjel természetesen nem
        számít).
    */
    
    int szam;
    int hanyszor = 0;
    
    do
    {
        printf("Egesz szam (vege: 0): ");
        scanf("%d", &szam);
        if (szam > 0)
        {
            hanyszor++;
        }      
    } while (szam != 0);

    printf("\n");
    printf("Pozitiv elemek szama: %d\n", hanyszor);
    
    return 0;
}
