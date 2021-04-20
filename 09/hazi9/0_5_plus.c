#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
    FILE *fp;
    char filename[SIZE] = "out.txt";
    char filename_2[SIZE] = "out_2.txt";
    char buffer[SIZE];
    int count = 0;
    char c;

    fp = fopen(filename, "r");
    printf("# in.txt sikeresen megnyitva\n");
    FILE *fp_2 = fopen(filename_2, "w");
    
    printf("# 0,5-nél nagyobb számok szűrése...\n");
    
    

    while(fgets(buffer, SIZE, fp)) 
    {
        if (atof(buffer) > 0.5)
        {
            fprintf(fp_2, buffer);
        }  
    }
    
    for (c = getc(fp); c != EOF; c = getc(fp))
    {    
        if (c == '\n')
        {    
            count = count + 1;
        }
    }
    
    fclose(fp);
    fclose(fp_2);
    printf("# out.txt bezárva\n");
    printf("# in.txt-be kiírt számok mennyisége: %d db", count);
    
    printf("\n");

    exit(0);
}