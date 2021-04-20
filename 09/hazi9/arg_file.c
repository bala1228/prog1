#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "prog1.h"

int main(int argc, char *argv[])
{
    FILE *fp;
    char *filename = argv[1];

    fp = fopen(filename, "r");
    
    if (argc != 2)
    {
        printf("Hiba! Adja meg egy szöveges állomány nevét!\n");
        exit(1);
    }

    if (fp == NULL)
    {
        printf("Hiba! A %s nevű file-t nem sikerült megnyitni!", filename);
        exit(2);
    }
    



    return 0;
}