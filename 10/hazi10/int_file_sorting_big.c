#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

// Egyszerű buborékrendezés
void bubble_sort(int array[], int array_size)
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
    int index = 0;
    FILE *fp;
    char *filename = argv[1];
    char *buffer = malloc(3000000 * sizeof(int));
    int *numbers = malloc(3000000 * sizeof(int));
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Hiba a fájl megnyitásakor!\n");
        exit(1);
    }

    while(fgets(buffer, SIZE, fp)) 
    {
        buffer[strlen(buffer) - 1] = '\0';
        numbers[index] = atoi(buffer);
        index++;
    }
    
    bubble_sort(numbers, SIZE);
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n", numbers[i]);
    
    }
    
    fclose(fp);

    exit(0);
}