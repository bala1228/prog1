#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_number_of_lines(FILE *fp)
{
    char c;
    int counter = 0;
    
    for (c = getc(fp); c != EOF; c = getc(fp))
    {    
        if (c == '\n')
        {    
            counter++;
        }
    }

    return counter;
}

int main(int argc, char *argv[])
{
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    
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
    
    printf("%d", get_number_of_lines(fp));

    exit(0);
}