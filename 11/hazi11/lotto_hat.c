#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1 = 1, x2 = 1, x3 = 1, x4 = 1, x5 = 1, x6 = 1;

    while ((x1 + x2 + x3 + x4 + x5 + x6 != 90) && 
            (x1 * x2 * x3 * x4 * x5 * x6 != 996300) &&
            (x1 != x2 || x1 != x3 || x2))
    {
        x1++;
        x2++;
        x3++;
        x4++;
        x5++;
        x6++;
    }

    printf("%d %d %d %d %d %d", x1, x2, x3, x4, x5, x6);    

    return 0;
}