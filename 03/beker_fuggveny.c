#include <stdio.h>

int get_int()
{
    int n;
    scanf("%d", &n);

    return n;
}

int main()
{
    printf("Adj meg egy számot!\n");
    int szam = get_int();

    printf("A szám %d.\n", szam);

    return 0;

}