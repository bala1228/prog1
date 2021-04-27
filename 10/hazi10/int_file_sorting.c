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
    if (argc != 2)
    {
        fprintf(stderr ,"Adja meg a file nevét!\n");
        exit(1);
    }
    char buffer[SIZE];
    int numbers[SIZE];
    int i = 0;

    FILE *f = fopen(argv[2], "r");
    fscanf(f, "%s", buffer);
    
    printf("*%s", buffer);
    
    puts("");
    
    //sorting(buffer);
    
    return 0;
}