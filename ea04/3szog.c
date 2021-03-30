#include <stdio.h>

double valid_triangle(double a, double b, double c)
{
    if (a < 0 || b < 0 || c < 0)
    {
        printf("nem megszerkeszthető\n");
    }
    else
    {
        if ((a + b) < c || (a + c) < b || (b + c) < a)
        {
            printf("nem megszerkeszthető\n");
        }
        else
        {
            printf("megszerkeszthető\n");
        }
    }

    return 0;
    
}

int main()
{
    double a, b, c;
    
    printf("Adja meg a háromszög 3 oldalát!\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    valid_triangle(a, b, c);
    
    return 0;
}