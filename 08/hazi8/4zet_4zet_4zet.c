#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int sum_of_squares(int numbers)
{
    int sum = 0;

    for (int i = 1; i <= numbers; i++)
    {
        sum = sum + (i * i);
    }
    
    return sum;
}

int square_of_sums(int n)
{
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        sum = sum + (i + 1);
    }

    return sum * sum;
}

int main()
{
    int numbers = 100;

    printf("Az első száz természetes szám összegének a négyzete és\n");
    printf("az első száz természetes szám négyzetösszege közti különbség: ");
    printf("%d\n", (square_of_sums(numbers) - sum_of_squares(numbers)));

    
    return 0;
}