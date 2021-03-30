#include <stdio.h>

int valid_triangle(double a, double b, double c)
{
    //van-e negatív oldala
    if (a < 0 || b < 0 || c < 0)
    {
        return 0;
    }
    else
    {
        //háromszög egyenlőtlenség
        if ((a + b) < c || (a + c) < b || (b + c) < a)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

int main()
{
    double a, b, c;
    
    printf("Adja meg a háromszög 3 oldalát!\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    int szerkesztheto = valid_triangle(a, b, c);
    printf("Megszerkeszthető: %s\n", szerkesztheto ? "igen" : "nem");
    
    return 0;
}