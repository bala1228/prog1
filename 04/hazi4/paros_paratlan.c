#include <stdio.h>

int is_even(int n)
{
    if (n % 2 == 0)
    {
        return 1;   //igaz (páros)
    }
    else
    {
        return 0;   //hamis (páratlan)
    }
}

int is_odd(int n)
{
    n = is_even(n);
    if (n == 0)
    {
        return 1;   //igaz (páratlan)
    }
    else
    {
        return 0;   //hamis (páros)
    }
    
}

int egesz_input(int szam)
{
    printf("Adjon meg egy egész számot: ");
    scanf("%d", &szam);

    return szam;
}

int main()
{
    int szam;
    szam = egesz_input(szam);
    int paratlan = is_odd(is_even(szam));

    printf("Páros: %s\n", paratlan ? "igen" : "nem");

    return 0;
}