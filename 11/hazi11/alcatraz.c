#include <stdio.h>
#include <stdlib.h>
 
 
int main()
{
    int* cella = (int*)calloc(600, sizeof(int));
    for (int i = 1; i <= 600; i++)
    {
        for (int j = 1; j <= 600; j++)
        {
            if(j % i == 0)
            {
                cella[i - 1] = 1;
            }
            else
            {
                cella[i - 1] = 0;
            }
        }
    }
    for (int i = 1; i <= 600; i++)
    {
        printf("index %d : %d\n", i, cella[i - 1]);
        /*
        if (cella[i - 1] == 1)
        {
            printf("%d", i);
        }
        */
    }

    free(cella);

    return 0;
}