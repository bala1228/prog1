#include <stdio.h>

int main()
{
    int szam;
    printf("Adj meg egy egész számot!\n");
    scanf("%d", &szam);
    
    //páros vagy páratlan
    if (szam % 2 == 0)
    {
        printf("A szám páros.\n");
    
    }
    else
    {
        printf("A szám páratlan.\n");
    }   
    
    return 0;
}
    
