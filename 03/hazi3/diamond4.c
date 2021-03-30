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

    