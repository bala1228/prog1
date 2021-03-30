#include <stdio.h>

int main()
{
    int magassag, szelesseg;
    
    printf("Mi a téglalap magassága?\n");
    scanf("%d", &magassag);
    printf("Mi a téglalap szélessége?\n");
    scanf("%d", &szelesseg);

    for (int i = 0; i < magassag; i++)
    {
        for (int j = 0; j < szelesseg; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    
    return 0;
}