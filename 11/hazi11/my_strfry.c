#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void my_strfry(char *string)
{
    int len = strlen(string);
    if (len > 0)
    for (int i = 0; i < len - 1; ++i)
    {
        int j = rand() % (len - i) + i;
        char c = string[i];
        string[i] = string[j];
        string[j] = c;
    }
}

int main()
{
    char *string = "egy";
    printf("Elotte: %s\n", string);
    my_strfry(string);
    printf("Elotte: %s\n", string);

    return 0;
}