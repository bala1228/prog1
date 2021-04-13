#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "prog1.h"
#define SIZE 10000

void sum_digits(char array[])
{
    int length = strlen(array);
    int counter = 0;
    for (size_t i = 0; i < length; i++)
    {
        counter = counter +  (array[i] - '0');
    }
    
    printf("A számjegyek összege: %d\n", counter);
}

int main()
{
    string input = get_string("Szám: ");

    sum_digits(input);
    
    return 0;
}