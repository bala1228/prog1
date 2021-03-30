#include <stdio.h>
#include "prog1.h"
// Az angol abc mérete
#define SIZE 26

// Feltölti a tömböt az angol abc karaktereivel.
void abc_fill(char tomb[])
{
    for (char c = 'a'; c <= 'z'; c++)
    {
        tomb[c - 'a'] = c;
    }
    
    tomb[SIZE] = '\0';
}

int main()
{
    // A tömb méretét 1-el növeljük az abc méretéhez képest,
    // mivel "kell a hely" a tömbön belül a \0-nak.
    char abece[SIZE + 1];
    abc_fill(abece);
    
    printf("%s\n", abece);
    
    return 0;
}