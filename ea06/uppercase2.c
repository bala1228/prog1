#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "prog1.h"

int main()
{
    string s = get_string("Elotte: ");
    printf("Utana: ");

    int hossz = strlen(s);
    for (int i = 0; i < hossz; i++)
    {
        char c = s[i];
        printf("%c", toupper(c));
    }
    puts("");
    
    return 0;
}