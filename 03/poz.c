#include <stdio.h>

int main()
{
    //do-while ciklussal pozitív szám beolvasása

    int szam;

    while (1)
    {
        printf("Pozitív egész: ");
        scanf("%d", &szam);
        if (szam > 0)
        {
            break;
        }
    }
    

    printf("------------------------------------------------\n");
    printf("A megadott szám: %d\n", szam);
    



    return 0;
}