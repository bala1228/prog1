#include <stdio.h>
#include <string.h>
#include "prog1.h"

// Az s alapsztringben keressük a c karakter utolsó előfordulásának a helyét.
// Visszatérési érték: a c utolsó előfordulásának az indexe az s-ben.
// Ha nincs benne: -1 a visszatérési érték.
int rfind_char(string s, char c)
{
    int n = strlen(s);
    
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == c)
        {
            return i;
        }
    }
    
    return -1;
}

int main()
{
    string s = "macilaci";
    char c = 'y';

    // Formázás a screenshot miatt, eredetileg 1 sor.
    printf("'%c' karakter helye visszafelé a '%s' string-ben: ", c, s);
    printf("%d\n", rfind_char(s, c));	

    return 0;
}
