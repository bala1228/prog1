#include <stdio.h>

//aritmetikai műveletek

int main()
{
    int a = 20;
    int b = 3;
    
    // +
    printf("%d + %d = %d\n\n\n", a, b, a+b);
    
    // -
    int kivonas = a - b;
    printf("%d - %d = %d\n\n\n", a, b, kivonas);
    
    // *
    printf("%d * %d = %d\n\n\n", a, b, a*b);
    
    // /
    printf("%d / %d = %d\n", a, b, a/b);
    printf("%lf / %lf = %lf\n\n\n", 20.0, 3.0, 20.0 / 3.0);
    
    // %
    printf("%d %% %d = %d\n\n\n", a, b, a % b);
    
    
    return 0;
}
    
