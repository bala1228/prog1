#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog1.h"
#define SIZE 100

// https://arato.inf.unideb.hu/szathmary.laszlo/pmwiki/index.php?n=Prog1.20200409b
// csak alfanumerikus karakterek(a-z, A-Z, 0-9 és '_')
// számjegy nem lehet az elején
// legalább 1 karakter hosszú
int is_valid_c_identifier(const char* input)
{
    int length = strlen(input);
    printf("* lenght: %d\n", length);
    
    if (length < 1)
    {  
        return 0;    
    }
    if (input[0] >= '0' && input[0] <= '9')
    {
        return 0;
    }
    for (int i = 0; i < length; i++) 
    {
        if (input[i] < '0') 
        {
            return 0;
        }
        if (input[i] > '9' && input[i] < 'A')
        { 
            return 0;
        }
        if (input[i] > 'Z' && input[i] < 'a') 
        {
            if (input[i] != '_')
            {
                return 0;
            }
        }
        if (input[i] > 'z')
        {
            return 0;
        } 
    }

    return 1;
}

int main()
{
    printf("Adj meg stringeket '*' végjelig!\n\n");
    
    // Beolvasás "*" végjelig
    while (1)
    {
        char* input = get_string("Input: ");

        if (strchr(input, '*') != NULL)
        {
            exit(0);
        }
        
        printf("*%d\n", is_valid_c_identifier(input));
    }
    
    return 0;
}