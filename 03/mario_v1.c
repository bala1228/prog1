#include <stdio.h>

int main()
{
    int n;
    printf("magasság: ");
    scanf("%d", &n);

    printf("\n");

    for (int i = 0; i <= n; i++)
    {
        //rajzoljunk ki i db téglát
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    
  
    
    
    
    
    return 0;
}