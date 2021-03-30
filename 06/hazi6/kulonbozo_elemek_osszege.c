#include <stdio.h>

int get_int_between(int min, int max)
{
    int szam;
    while (1)
    {
        printf("Szám: ");
        scanf("%d", &szam);
        if (szam >= min && szam <= max || szam == 0)
        {
            return szam;
        }
        puts("Ez a szám intervallumon kívüli!");
    }
    
}

int get_different(int tomb[], int meret)
{
    int counter = 0;
    for (int i = 1; i < meret; i++)
    {
        if (tomb[i] == 1)
        {
            counter++;
        }
    }
    
    return counter;
}

void kiir_ertekek(int tomb[], int meret)
{
    printf("Ezek a szmok sorrendben: ");
    for (int i = 1; i < meret; i++)
    {
        if (tomb[i] == 1)
        {
            printf("%d ", i);
        }
    }
    puts("");
}

int main()
{
    int tomb[100];
    for (int i = 0; i < 100; i++)
    {
        tomb[i] = 0;
    }
    
    puts("Adj meg számokat 1-99 között (zárt)");
    while (1)
    {
        int szam = get_int_between(1, 99);
        if (szam == 0)
        {
            break;
        }
        tomb[szam] = 1;
    }
    
    printf("Különböző számok: %d.\n", get_different(tomb, 100));

    kiir_ertekek(tomb, 100);
    
    return 0;
}