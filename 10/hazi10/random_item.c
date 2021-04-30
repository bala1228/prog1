#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int choice(const int n, const int tomb[])
{
    int index = rand() % n;

    return tomb[index];
}

int main()
{   
    srand((time(NULL)));

    int array[10] = { 0 };
    int array_size = 10;
    for (int i = array_size; i != 0; i--)
    {
        array[i] = rand() % 1024;
    }
    for (int i = array_size; i != 0; i--)
    {
        printf("%d ", array[i]);
    }
    puts("");
    
    printf("%d\n", choice(array_size, array));

    return 0;
}