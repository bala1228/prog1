#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void string_to_upper(char *string)
{
    for (int i = 0; string[i] != '\0'; i++) 
    {
        if (string[i] >= 'a' && string[i] <= 'z') 
        {
            string[i] = string[i] - 32;
        }
    }
}

int my_strcmpi(const char *s1, const char *s2)
{   
    const unsigned char *p1 = (const unsigned char *) s1;
    const unsigned char *p2 = (const unsigned char *) s2;
    unsigned char c1, c2;
    do
    {
        c1 = (unsigned char) *s1++;
        c2 = (unsigned char) *s2++;
        if (c1 == '\0')
        {
            return c1 - c2;
        }
    }
    while (c1 == c2);
    
    return c1 - c2;
}

int main()
{
    char *string_1 = "ez";
    char *string_2 = "Ez";
    string_to_upper(string_1);
    
    printf("%s\n", string_1);
    
    return 0;
}