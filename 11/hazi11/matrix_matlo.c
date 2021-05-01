#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void kiif_mellekatlo(int n, int matrix[n][n])
{
    int oszlop = 0;

    for (int sor = n - 1; sor != -1; sor--)
    {
        printf("%d ", matrix[sor][oszlop]);
        oszlop++;
    }
    
}

int main()
{
    int matrix[][6] = {
        {1, 2, 3, 4, 5, 9},
        {1, 2, 3, 4, 9, 6},
        {1, 2, 3, 9, 5, 6},
        {1, 2, 9, 4, 5, 6},
        {1, 9, 3, 4, 5, 6},
        {9, 2, 3, 4, 5, 6},
    };
    int sorok_es_oszlopok = 6;
    kiif_mellekatlo(sorok_es_oszlopok, matrix);

    return 0;
}