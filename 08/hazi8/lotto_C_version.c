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

// Buborék rendezés
void array_sorting(int tomb[], int meret)
{
    for (int i = 1; i < meret; i++)
    {
        for (int j = meret - 1; j >= i; j--)
        {
            if (tomb[j - 1] > tomb[j])
            {
                int tmp = tomb[j - 1];
                tomb[j - 1] = tomb[j];
                tomb[j] = tmp;
            }   
        }   
    }
    for (int i = 0; i < meret - 1; i++)
    {
        printf("%d, ", tomb[i]);
    }
    printf("%d\n", tomb[meret - 1]);
}

int main()
{
    int n = 5;
    int min = 1;
    int max = 90;
    
    /*
    // Bekérjük hány random számot genráljunk.
    printf("Hány db random számot kérsz?\n");
    scanf("%d", &n);
    // Bekérjük a lehetséges legkisebb értéket.
    printf("Alsó határ: ");
    scanf("%d", &min);
    // Bekérjük a lehetséges legnagyobb értéket.
    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &max);
    */

    int test[n];
       
    for (int i = 0; i < n; i++)
    {
        test[i] = (rand() % (max - min + 1) + min);
    }
    
    array_sorting(test, n);
    test_flow(test, max, min, n);
    
    
    puts("");

    return 0;
}	