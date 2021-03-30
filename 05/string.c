#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "prog1.h"

int is_palindrome(string text)
{
    int i = 0; 
    int j = strlen(text) - 1;

    while (i < j)
    {
        if (text[i] != text[j])
        {
            return 0;
        }
        i++, j--;
    }
    
    return 1;
}

int find_char_in_string(string s, char c)
{
    int n = strlen(s);
    
    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
        {
            return i;
        }
    }
    
    return -1;
}

int contains_char(string s, char c)
{
    return find_char_in_string(s, c) >= 0;
    
}

int main()
{
    string s = "geza";
    char c = 'p';

    printf("%d\n", strlen(s));
    printf("%s palindróm?: %s\n", s, is_palindrome(s) ? "igen" : "nem" );
    printf("%c helye a string-ben: %d\n", c, find_char_in_string(s, c));
    printf("Benne van a(z) '%c' a '%s' string-ben? %s\n", c, s, contains_char(s, c) ? "Igen." : "Nincs benne.");

    return 0;
}