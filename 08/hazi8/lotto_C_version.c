#include <stdio.h>
#include <stdlib.h>

int test_flow(int tomb[], int max, int min, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (tomb[i] > max)
        {
            printf("Túlcsordulás!\n");
            exit(1);
        }
        else if (tomb[i] < min)
        {
            printf("Alulcsordulás!\n");
            exit(2);
        }
    }
    
    printf("OK\n");
    exit(0);
    
}

void array_sorting(int tomb[], int meret)
{
    // TODO
}

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
    
    puts("");

    test_flow(test, max, min, n);

    return 0;
}	