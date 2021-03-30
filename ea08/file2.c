#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "prog1.h"

int main()
{
    string fajlnev = "out.txt";

    FILE *fp = fopen(fajlnev, "w");

    if (fp == NULL)
    {
        printf("Hiba a %s fájl megnyitásakor!\n", fajlnev);
        exit(1);
    }
    
    fprintf(fp, "Hello\n");
    fprintf(fp, "2+2 = %d\n", 2 + 2);
    fprintf(fp, "pi értéke: %lf\n", M_PI);
    char c = 'a';
    fprintf(fp, "az abc első betűje: %c\n", c);

    fclose(fp);

    
    return 0;
}