#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void primeFactors(int n, int numbers[])
{
    int j = 0;

    
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        printf("%d ", 2);
        numbers[j] = 2;
        j++;
        n = n / 2;
    }
  
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            printf("%d ", i);
            numbers[j] = i;
            j++;
            n = n / i;
        }
    }
  
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2) 
    {
        printf ("%d ", n);
        numbers[j] = n;
        j++;
    }
}

int main()
{
    int szorzat = 996300;
    int osszeg = 90;
    int szamok[10] = {0};
    primeFactors(szorzat, szamok);
    
    int x1 = 1, x2 = 1, x3 = 1, x4 = 1, x5 = 1, x6 = 1;

    while ((x1 + x2 + x3 + x4 + x5 + x6 != 90) && (x1 * x2 * x3 * x4 * x5 * x6 != 996300))
    {
        x1++;
        x2++;
        x3++;
        x4++;
        x5++;
        x6++;
        if (x1 == x2 || x3 || x4 || x5 || x6)
        {
            x1++;
        }
    }

    //printf("%d %d %d %d %d %d", x1, x2, x3, x4, x5, x6);    
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", szamok[i]);
    }
    puts("");

    return 0;
}