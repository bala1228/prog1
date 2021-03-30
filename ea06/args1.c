#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "prog1.h"

int main(int argc, string argv[])
{
    printf("argc: %d\n", argc);
    puts("");

    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    
    return 0;
}