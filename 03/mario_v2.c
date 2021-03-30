#include <stdio.h>

int main()
{
    int n;
    printf("magasság: ");
    scanf("%d", &n);

    printf("\n");

    for (int i = 0; i <= n; i++)
    {
        int szokozok = n - i;
        int teglak = i;
        
        for (int j = 0; j < szokozok; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < teglak; k++)
        {
            printf("#");
        }
        
        printf("\n");
    }
    
    return 0;
}