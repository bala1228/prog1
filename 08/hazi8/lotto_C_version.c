#include <stdio.h>
#include <stdlib.h>

int test_flow(int tomb[], int max, int min, int size)
{
    for (int i = 0; i < size; i++)
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

// Buborék rendezés
void array_sorting(int tomb[], int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = size - 1; j >= i; j--)
        {
            if (tomb[j - 1] > tomb[j])
            {
                int tmp = tomb[j - 1];
                tomb[j - 1] = tomb[j];
                tomb[j] = tmp;
            }   
        }   
    }
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d, ", tomb[i]);
    }
    printf("%d\n", tomb[size - 1]);
}

int main()
{
    int size = 0;
    int min = 0;
    int max = 0;
    
    
    // Bekérjük hány random számot genráljunk.
    printf("Hány db random számot kérsz?\n");
    scanf("%d", &size);
    // Bekérjük a lehetséges legkisebb értéket.
    printf("Alsó határ: ");
    scanf("%d", &min);
    // Bekérjük a lehetséges legnagyobb értéket.
    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &max);

    int test[size];
       
    for (int i = 0; i < size; i++)
    {
        test[i] = (rand() % (max - min + 1) + min);

        for (int j = 1; j < size; j++)
        {
            if (test[j] == test[i])
            {
                test[i] = (rand() % (max - min + 1) + min);
            }
        }
    }

    array_sorting(test, size);
    test_flow(test, max, min, size);
    
    
    puts("");

    return 0;
}	