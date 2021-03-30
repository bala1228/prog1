#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "prog1.h"

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Hiba! Adjon meg pontosan egy parametert!");
        return 1;
    }
    printf("Hello %s!\n", argv[1]);
    
    return 0;
}