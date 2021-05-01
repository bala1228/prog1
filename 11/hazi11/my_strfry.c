#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void my_strfry(char *string)
{
    srand(time(NULL));
    
    int length = strlen(string);
    if (length > 0)
    for (int i = 0; i < length - 1; ++i)
    {
        int j = (rand() % (length - i)) + i;
        char c = string[i];
        string[i] = string[j];
        string[j] = c;
    }
}

int main()
{
    char string[] = "Programozas 1";
    printf("Elotte: %s\n", string);
    my_strfry(string);
    printf("Elotte: %s\n", string);

    return 0;
}