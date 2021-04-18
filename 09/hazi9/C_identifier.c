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
    // TODO
    
    return 0;
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
        
        is_valid_c_identifier(input);
    }
    
    return 0;
}