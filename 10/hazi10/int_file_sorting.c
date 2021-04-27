#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define SIZE 1000

void sorting(char array[])
{
    
}

// Egyszerű buborékrendezés
void bubble_sort(char array[], int array_size)
{
    for (int i = 1; i < array_size; i++)
    {
        for (int j = array_size - 1; j >= i; j--)
        {
            if (array[j - 1] > array[j])
            {
                int tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }   
        }   
    }
}

int main(int argc, char *argv[])
{
    FILE *f = fopen("specification.txt", "r");
    char currentline[SIZE];
    int index = 0;
    int numbers[SIZE];


    while (fgets(currentline, sizeof(currentline), f) != NULL) 
    {
        printf("got line: %s\n", currentline);
        
    }

    fclose(f);
}