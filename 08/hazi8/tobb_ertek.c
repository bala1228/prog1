#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Generál egy random 10 elemű tömböt min és max között, majd visszadja ezek
// közül a legkisebb és a legnagyobb elemet
void array_min_max_avg(int min, int max, int array[])
{
    int temp_min = max, temp_max = min; 
    float avg = 0;
    
    // Értékek generálása és tömb feltöltése
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = (rand() % (max - min + 1) + min);
    }
    // Tömb elemeinek kiírása
    for (int i = 0; i < (SIZE - 1); i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d\n", array[SIZE - 1]);

    // Min és max keresése
    for (int i = 0; i < SIZE; i++)
    {
        avg += array[i];

        if (temp_min > array[i])
        {
            temp_min = array[i];
        }
        if (temp_max < array[i])
        {
            temp_max = array[i];
        }
    }
    avg = avg / SIZE;
    
    printf("Legkisebb elem: %d\n", temp_min);
    printf("Legnagyobb elem: %d\n", temp_max);
    printf("Az elemek átlaga: %.1f\n", avg);
}

int main()
{
    int min = 10;
    int max = 99;
    int array[SIZE];

    array_min_max_avg(min, max, array);
       
    return 0;
}