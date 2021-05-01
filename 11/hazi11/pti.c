#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BUFFSIZE 200

void string_to_upper(char s[])
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        s[i] = toupper(s[i]);
    }
}   

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
    printf("Név: ");

    while (fgets(line, BUFFSIZE, fp))
    {
        line[strlen(line) - 1] = '\0';
        p = strtok(line, ",");
        nev = p;
        p = strtok(NULL, ",");
        kor = atoi(p);
        p = strtok(NULL, ",");
        szak = p;
        string_to_upper(szak);
        nev[0] = toupper(nev[0]);
        
        if (strcmp(szak ,"PTI") == 0)
        {
            printf("%s ", nev);
        }
        
    }
    puts("");
    
    fclose(fp);

    return 0;
}