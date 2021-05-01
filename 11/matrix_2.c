#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void kiir(int sorok, int oszlopok, int matrix[][oszlopok])
{
    for (int sor = 0; sor < sorok; sor++)
    {
        for (int oszlop = 0; oszlop < oszlopok; oszlop++)
        {
            printf("%d\t", matrix[sor][oszlop]);
        }
        puts("");
    }
    
}

int get_elemek_osszege(int n, int m, int matrix[n][m])
{
    int osszeg = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            osszeg += matrix[i][j];
        }
        
    }
    
    return osszeg;
}

void kiir_foatlo(int sorok, int matrix[][sorok])
{
    for (int sor = 0; sor < sorok; sor++)
    {
        printf("%d\t", matrix[sor][sor]);
    }    
    puts("");
    
    
}

int main()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int sorok = 3;
    int oszlopok = 3;
    kiir(sorok, oszlopok, matrix);
    puts("");

    kiir_foatlo(sorok, matrix);

    printf("%d\n", get_elemek_osszege(sorok, oszlopok, matrix));

    return 0;
}