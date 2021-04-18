#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

// https://arato.inf.unideb.hu/szathmary.laszlo/pmwiki/index.php?n=Prog1.20200409b
// csak alfanumerikus karakterek(a-z, A-Z, 0-9 és '_')
// számjegy nem lehet az elején
// legalább 1 karakter hosszú
int is_valid_c_identifier(const char* input)
{
    printf("*Beolvasás: %s", input);
    puts("");
    
    return 0;
}

int main()
{
    char* input;

    // Beolvasás "*" végjelig
    while (1)
    {
        printf("Enter a input: ");
        fgets(input, SIZE, stdin);
        //input[(strlen(input) - 1)] = '\0';

        if (strchr(input, '*') != NULL)
        {
            exit(0);
        }
        
        is_valid_c_identifier(input);
    }
    
    return 0;
}