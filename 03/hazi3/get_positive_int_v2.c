#include <stdio.h>

/*
A gyakorlaton láttuk a get_positive_int() nevű függvényt, amit végtelen ciklussal oldottunk meg. 
Írjuk át ezt a függvényt úgy, hogy vagy while ciklust (nem végtelen ciklust), 
vagy pedig do-while ciklust használunk (lehet választani).
*/

int get_positive_int()
{
    int n;
    
    scanf("%d", &n);
    do
    {   
        if (n <= 0)
        {
            printf("Adj meg egy új számot!\n");
            scanf("%d", &n);
        }
    } while (n <= 0);
    
    return n;
}

int main()
{
    printf("Adj meg egy pozitív egész számot!\n");
    int szam = get_positive_int();

    printf("A megadott szám: %d\n", szam);

    return 0;
}
