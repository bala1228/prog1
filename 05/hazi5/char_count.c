#include <stdio.h>
#include <string.h>
#include "prog1.h"

// Az "s" sztringben a "c karakter hányszor fordul elő                             
int char_count(string s, char c)
{
    int n = strlen(s);
    int count = 0;
    
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == c)
        {
            count++;
        }
    }
    
    return count;
}

int main()
{
    string s = "elemer";
    char c = 'a';

    // Formázás a screenshot miatt
    printf("'%c' karakter benne van a(z) ", c); 
    printf("'%s' string-ben ennyiszer: ", s);
    printf("%d\n", char_count(s, c));
    
    return 0;
}
