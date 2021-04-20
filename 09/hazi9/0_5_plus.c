#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
    FILE *fp, *fp_2;
    char filename[SIZE] = "in.txt";
    char filename_2[SIZE] = "out.txt";
    char buffer[SIZE];
    int count = 0;
    char c;

    fp = fopen(filename, "r");
    printf("# in.txt sikeresen megnyitva\n");
    fp_2 = fopen(filename_2, "w");
    
    printf("# 0,5-nél nagyobb számok szűrése...\n");
    
    
    while(fgets(buffer, SIZE, fp)) 
    {
        if (atof(buffer) > 0.5)
        {
            fprintf(fp_2, buffer);
        }  
    }
    
    fclose(fp_2);
    fp_2 = fopen(filename_2, "r");
    
    for (c = getc(fp_2); c != EOF; c = getc(fp_2))
    {    
        if (c == '\n')
        {    
            count++;
        }
    }
    
    fclose(fp);
    fclose(fp_2);
    printf("# out.txt bezárva\n");
    printf("# in.txt-be kiírt számok mennyisége: %d db", count);
    
    printf("\n");

    exit(0);
}