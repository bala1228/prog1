#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

// https://arato.inf.unideb.hu/szathmary.laszlo/pmwiki/index.php?n=Prog1.20200407a

typedef struct 
{
    int min;
    int max;
    int avg;
} Min_Max_Avg;

int search_min(int array[], Min_Max_Avg result)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (result.min > array[i])
        {
            result.min = array[i];
        }
    }
    
    return result.min;
}

int search_max(int array[], Min_Max_Avg result)
{
     for (int i = 0; i < SIZE; i++)
    {
        if (result.max < array[i])
        {
            result.max = array[i];
        }
    }
    
    return result.max;
}

int calculate_avg(int array[], Min_Max_Avg result)
{
    for (int i = 0; i < SIZE; i++)
    {
        result.avg += array[i];
    }
    result.avg = result.avg / 2;

    return result.avg;
}

// Tömb elemeinek kiírása
void array_output(int array[])
{
    for (int i = 0; i < (SIZE - 1); i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d\n", array[SIZE - 1]);
}

// Értékek generálása és tömb feltöltése
void fill_array(int array[], int min, int max)
{
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = (rand() % (max - min + 1) + min);
    }
}

Min_Max_Avg get_min_max_avg()
{
    int min = 10;
    int max = 99;
    int array[SIZE];
    
    fill_array(array, min, max);
    array_output(array);

    Min_Max_Avg result = {search_min(array, result), search_max(array, result), calculate_avg(array, result)};

    /*// Min és max keresése
    for (int i = 0; i < SIZE; i++)
    {    
        result.avg += array[i];

        if (result.min > array[i])
        {
            result.min = array[i];
        }
        if (result.max < array[i])
        {
            result.max = array[i];
        }
    }
    result.avg = result.avg / SIZE;
    */
    return result; 
}    

int main()
{
    
    //srand(time(NULL));
    
    //array_min_max_avg(min, max, array);
    Min_Max_Avg output = get_min_max_avg();

    printf("Legkisebb elem: %d\n", output.min);
    printf("Legnagyobb elem: %d\n", output.max);
    printf("Az elemek átlaga: %.1f\n", output.avg);

    return 0;
}
