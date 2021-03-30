#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog1.h"

int main(int argc, string argv[])
{
    // Ha nem 2 paraméter van megadva, akkor hibaüzenettel kilép
    // a program.
    if (argc != 3)
    {
        printf("Hiba! Két paramétert (számot) kell megadni.\n");
        exit(1);
    }
    // Összeadja a 2 paramétert.
    else
    {   
        printf("%d\n", atoi(argv[1]) + atoi(argv[2]));
    }
    
    exit(0);
}