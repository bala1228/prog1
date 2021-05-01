#include <stdio.h>
#include <string.h>

int main()
{
    char sor[] = "aa bbbb cc dd";
    char *p;

    p = strtok(sor, " ");
    while (p != NULL)
    {
        printf("%s\n", p);
    p = strtok(NULL, " ");    
    }

    return 0;
}