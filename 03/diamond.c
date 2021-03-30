#include <stdio.h>

/*
Írjunk egy programot, ami interaktív módon bekéri egy gyémánt magasságát (egész szám).

Először ellenőrizzük le, hogy helyes-e a bemenet. Csak pozitív páratlan számot fogadjunk el, 
ellenkező esetben írjunk ki egy hibaüzenetet és a program álljon le.
*/

int get_magassag()
{
    int n;
    
    printf("magasság: ");
    scanf("%d", &n);
    while (1)
    {
        if (n % 2 == 0)
        {
            printf("A megadott szám páros. Adjon meg egy páratlan egész számot!\n");
            scanf("%d", &n);
        }
        else
        {
            break;
        }
    }
    
    return n;
}

int main()
{
    
    int magassag = get_magassag();

    printf("\n");

    int szokozok = magassag / 2;
    int s = szokozok;
    int m = 1;
    

    //for (int i = 1; i < magassag; i++)
    //{
    //    
    //    for (int j = 0; j <= s; j++)
    //    {
    //        printf(" ");
    //    }
    //    for (int k = 1; k <= csillagok; k++)
    //    {
    //        printf("*");
    //    }
    //    csillagok += 2;
    //    s--;
    //    
    //    printf("\n");
    //    
    //}
    for (int i = magassag; i > 0; i++)
    {
        if (s != 0)
        {
            for (s ; s > 0; s--)
            {
                printf("#");
            }
            for (int j = 1; j <= magassag; j += 2)
            {
                printf("*");
            }
            

            printf("\n");
    //}
    //else
    //{
    //    for (s ; s > 0; s--)
    //    {
    //        printf(" ");
    //    }
    //    for (int m = 1; m <= magassag; m += 2)
    //    {
    //        printf("*");
    //    }
        }
    }
    

    return 0;
}