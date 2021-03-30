#include <stdio.h>

int main()
{
    //szám bekérése, vizsgálata és a pozitív, negatív, nulla szó érték szerinti kiírása
    int szam;
    printf("Adjon meg egy egész számot!\n");
    scanf("%d", &szam);

    if (szam < 0)
    {
        printf("negatív\n");
    }
    else if (szam > 0)
    {
        printf("pozitív\n");
    }
    else
    {
        printf("nulla\n");
    }
    
    
    return 0;
}