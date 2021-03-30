#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define SIZE 26

void abc_fill(char tomb[])
{
    int temp = 97;
    
    for (int i = 0; i < SIZE; i++)
    {
        tomb[i] = (char)temp;
        temp++;
    }
    
}

int main()
{
    char abece[SIZE];
    abc_fill(abece);
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("%c ", abece[i]);
    }
    puts("");

    return 0;
}