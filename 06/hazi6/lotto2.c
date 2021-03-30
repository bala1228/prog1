#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int min = 0;
    int max = 0;
    
    // Bekérjük hány random számot genráljunk.
    printf("Hány db random számot kérsz?\n");
    scanf("%d", &n);
    // Bekérjük a lehetséges legkisebb értéket.
    printf("Alsó határ: ");
    scanf("%d", &min);
    // Bekérjük a lehetséges legnagyobb értéket.
    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &max);
    
    int test[n];
       
    for (int i = 0; i < n; i++)
    {
        test[i] = (rand() % (max - min + 1) + min);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", test[i]);
    }
    puts("");


    return 0;
}	
