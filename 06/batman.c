#include <stdlib.h>
#include <stdio.h>
#include "prog1.h"
#include <string.h>


int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Hello World!\n");
    }
    else if (argc == 2)
    {
        string nev = argv[1];
        if (strcmp(nev, "Batman") == 0 || strcmp(nev, "Robin") == 0)
        {
            printf("Denevérveszély!\n");
        }
        else
        {
            printf("Hello %s!\n", nev);
        }
    }
    else
    {
        printf("Hiba! Maximum egy paraméter adható meg!\n");
        exit(1);       
    }
    
    return 0;
}