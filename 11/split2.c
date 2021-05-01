#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFSIZE 200

int main()
{
    FILE *fp = fopen("nevek.csv", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Hiba a file beolvasásakor!\n");
        exit(1);
    }
    
    char line[BUFFSIZE];
    char *p;
    char *nev, *szak;
    int kor;

    while (fgets(line, BUFFSIZE, fp))
    {
        line[strlen(line - 1)] = '\0';
        p = strtok(line, ",");
        nev = p;
        p = strtok(NULL, ",");
        kor = atoi(p);
        p = strtok(NULL, ",");
        szak = p;
        
        if (strcmp(szak ,"MI"))
        {
            printf("Név: %s, kor: %d, szak: %s", nev, kor, szak);
        }
        puts("");
    }
    
    fclose(fp);

    return 0;
}