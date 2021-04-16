#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Fisher–Yates keverés algoritmus
void fisher_yates_algorithm(int array[], int array_size)
{
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

int main()
{
    // Változók
    int output = 0;
    int min = 0;
    int max = 0;
    int i, temp;
    
    // Bekérjük hány random számot genráljunk.
    printf("Hány db random számot kérsz?\n");
    scanf("%d", &output);
    // Bekérjük a lehetséges legkisebb értéket.
    printf("Alsó határ: ");
    scanf("%d", &min);
    // Bekérjük a lehetséges legnagyobb értéket.
    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &max);

    int size = max - min + 1;

    int test[size];

    for (temp = 0, i = min; temp < size; temp++, i++)
    {
        test[temp] = i;
    }

    srand(time(NULL));
    
    fisher_yates_algorithm(test, size);

    for (i = 0; i < output; i++)
    {
        printf("%d ", test[i]);
    }
    puts("");
    

    return 0;
}
