#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Feladat:
// https://arato.inf.unideb.hu/szathmary.laszlo/pmwiki/index.php?n=Prog1.20200326d

// Fisher–Yates keverés algoritmus
void fisher_yates_algorithm(int array[], int array_size)
{
    srand(time(NULL));
    int temp = 0;
    
    for (int i = array_size - 1; i > 0; i--)
    {
        // Random index
        int r = rand() % i;
        // számok keverése
        temp = array[i];
        array[i] = array[r];
        array[r] = temp;
    }
}

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

// Kiírja az átadott tömb első n értékét
void output(int array[], int output_counter)
{
    bubble_sort(array, output_counter);
    
    for (int i = 0; i < output_counter; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");
}

int main()
{
    // Változók
    int output_counter = 0;
    int min = 0;
    int max = 0;
    int i, temp;
    
    // Bekérjük hány random számot genráljunk.
    printf("Hány db random számot kérsz?\n");
    scanf("%d", &output_counter);
    // Bekérjük a lehetséges legkisebb értéket.
    printf("Alsó határ: ");
    scanf("%d", &min);
    // Bekérjük a lehetséges legnagyobb értéket.
    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &max);
    
    int size = max - min + 1;
    int test[size];

    // Feltölti a tömböt az adott intervallumban
    for (temp = 0, i = min; temp < size; temp++, i++)
    {
        test[temp] = i;
    }
    
    fisher_yates_algorithm(test, size);

    output(test, output_counter);

    return 0;
}
