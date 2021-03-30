#include <stdio.h>

int get_magassag()
{
    int n;
    
    printf("magasság: ");
    scanf("%d", &n);
    while (1)
    {
        if (n <= 0)
        {
            printf("A megadott szám nem pozitív.\n"); 
            printf("Adjon meg egy pozitív egész számot!\n");
            scanf("%d", &n);
        }
        else
        {
            break;
        }
    }
    
    return n;
}

int main()
{
    int magassag = get_magassag();

    for (int i = 0; i <= magassag; i++)
    {
        int szokozok = magassag - i;
        int teglak = i;

        for (int j = 0; j < szokozok; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < teglak; k++)
        {
            printf("#");
        }
        
        printf("  ");

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        
        printf("\n");

    }

    return 0;
}
