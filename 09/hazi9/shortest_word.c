#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

// Megkap egy stringeket tartalmazó tömböt, annak hosszát, 
// illetve a legrövidebb szavak hosszát és kiírja a legrövidebb
// szavakat a tömbből
void output(char *array[], int array_length, int min_length)
{
    for (int i = 1; i < array_length; i++)
    {
        if (strlen(array[i]) == min_length)
        {
            printf("%s\n", array[i]);
        }
    }
}

// Stringeket tartalmazó tömbböl kiszámolja a legrövidebb
// hosszát
void shortest_words(char *array[], int array_length)
{
    int i = 0;
    int min_length = 10000;
    int storage[SIZE] = {0};

    for (int i = 1; i < array_length; i++)
    {
        //printf("%s\n", array[i]);
        if (strlen(array[i]) < min_length)
        {
            min_length = strlen(array[i]);
        }
    }
    // Kiírás
    output(array, array_length, min_length);
}


int main(int argc, char *argv[])
{
    // Ha nincs megadva parancsori argumentumként egy szó sem, 
    // akkor hibaüzenettel kilép a program.
    if (argc < 2)
    {
        printf("Nem adtál meg egyetlen szót sem!\n");
        exit(1);
    }
    else
    {      
        shortest_words(argv, argc);
    }   
    
    exit(0);
}