#include <stdio.h>

int main()
{
    //Írassuk 1-10 zárt intervallum értékeit.
    
    for (int i = 1; i <= 10; i++)
    {
        printf("%d\n", i);
    }

    printf("------------------------------------------------\n");
    
    //ugyanaz while ciklussal
    int j = 0;
    while (j <= 10)
    {
        printf("%d, ", j);
        j++;
    }
    printf("\n");
    
    return 0;
}