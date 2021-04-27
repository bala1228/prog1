#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    puts("Adj meg szamokat 0 vegjelig!");
    puts("");

    int *szamok = NULL;
    int elemszam = 0;

    while (1)
    {
        int szam;

        printf("Szam: ");
        scanf("%d", &szam);

        if (szam == 0)
        {
            break;
        }
        
        szamok = realloc(szamok, (elemszam + 1) * sizeof(int));
        if (szamok == NULL)
        {
            exit(1);
        }
        szamok[elemszam] = szam;
        elemszam++;
    }
    
    for (int i = 0; i < elemszam; i++)
    {
        printf("%d", szamok[i]);
    }
    puts("");

    free(szamok);

    return 0;
}