#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *filename = "in.txt";
    char *filename_2 = "out.txt";
    int bufferLength = 255;
    char buffer[bufferLength];

    FILE *fp = fopen(filename, "r");
    FILE *fp_2 = fopen(filename_2, "w");
    
    while(fgets(buffer, bufferLength, fp)) 
    {
        printf("%s", buffer);
        if (atof(buffer) > 0.5)
        {
            fprintf(fp_2, buffer);
        }
        
    }

    fclose(fp);

    return 0;
}