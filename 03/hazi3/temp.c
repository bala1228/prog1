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
            
            printf("A megadott szám nem pozitív. Adjon meg egy páratlan pozitív egész számot!\n");
            scanf("%d", &n);
        }
        else if (n % 2 == 0)
        {
            printf("A megadott szám páros. Adjon meg egy páratlan pozitív egész számot!\n");
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
    printf("\n");
    
    int csillag = 1;
    int szokoz = magassag / 2;
    
    for (int i = 0; i < (magassag / 2) + 1; i++)
    {
        for (int j = 0; j < szokoz; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < csillag; k++)
        {
            printf("*");
        }
        
        csillag += 2;
        szokoz--;
        printf("\n");

        


    }

    csillag = magassag - 2;
    szokoz = 1;
    
    for (int i = 0; i < magassag / 2; i++)
    {
        for (int j = 0; j < szokoz; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < csillag; k++)
        {
            printf("*");
        }

        csillag -= 2;
        szokoz++;
        printf("\n");
    }
    
        

    
    
    return 0;
}