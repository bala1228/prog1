#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
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
    
    //Fisher–Yates keverés algoritmus
    for (i = size - 1; i > 0; i--)
    {
        // Random index
        int r = rand() % i;
        //számok keverése
        temp = test[i];
        test[i] = test[r];
        test[r] = temp;
    }

    for (i = 0; i < output; i++)
    {
        printf("%d, ", test[i]);
    }
    
    return 0;
}