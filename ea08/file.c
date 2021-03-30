#include <stdio.h>
#include <string.h>
#include "prog1.h"
#include <stdlib.h>


#define MAX 1000

int main()
{
    string fajlnev = "szöveg.txt";
    char sor[MAX];
    
    FILE *fp = fopen(fajlnev, "r");

    if (fp == NULL)
    {
        printf("Hiba a %s fájl megnyitásakor!\n", fajlnev);
        exit(1);
    }
    
    
    while (fgets(sor, MAX, fp) != NULL)
    {
        sor[strlen(sor) - 1] = '\0';
        printf("%s\n", sor);
    }
    
    fclose(fp);

    return 0;
}