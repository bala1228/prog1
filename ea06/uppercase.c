#include <stdio.h>
#include <string.h>
#include "prog1.h"

int main()
{
    string s = get_string("Elotte: ");
    printf("Utana: ");

    int hossz = strlen(s);
    for (int i = 0; i < hossz; i++)
    {
        char c = s[i];

        if (c >= 'a' && c <= 'z')
        {
            printf("%c", c - 32);
        }
        else
        {
            printf("%c", c);
        }
    }
    
    
    return 0;
}