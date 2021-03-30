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
    int i, j;
    int magassag = get_magassag();

    printf("\n");
    
    for (i = 1; i <= magassag; i++)
    {
        for (j = 1; j <= magassag-i; j++)
        {  
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++)
        {  
            printf("*");
        }
        
        printf("\n");
    }

    for (i = 1; i <= magassag - 1; i++)
    {
        for (j = 1; j <= i; j++)
        { 
            printf(" ");
        }
        for (j = 1 ; j <= 2*(magassag - i) - 1; j++)
        {    
            printf("*");
        }       
        
        printf("\n");
    }

    return 0;
}