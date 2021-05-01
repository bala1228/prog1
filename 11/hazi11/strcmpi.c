#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void string_to_upper(char s[])
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        s[i] = toupper(s[i]);
    }
}    

int my_strcmpi(const char *s1, const char *s2)
{   
    char *temp_1 = strdup(s1);
    char *temp_2 = strdup(s2);
    
    string_to_upper(temp_1);
    string_to_upper(temp_2);

    char const *p1 = temp_1;
    char const *p2 = temp_2;
    char c1, c2;
    do
    {
        c1 = *p1++;
        c2 = *p2++;
        if (c1 == '\0')
        {
            break;
        }
    } while (c1 == c2);

    free(temp_1);
    free(temp_2);

    return c1 - c2;
}

int main()
{
    char s1[] = "AlAdAr";
    char s2[] = "aLadAR";
    
    printf("%d\n", my_strcmpi(s1, s2));
    
    return 0;
}