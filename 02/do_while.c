#include <stdio.h>

int main()
{
    //do-while ciklussal pozitív szám beolvasása

    int szam;

    do
    {
        printf("Adjon meg egy pozitív egész számot!\n");
        scanf("%d", &szam);
    } while (szam <= 0);            //rossz inputot kell itt megadni
    printf("------------------------------------------------\n");
    printf("A megadott szám: %d\n", szam);
    



    return 0;
}