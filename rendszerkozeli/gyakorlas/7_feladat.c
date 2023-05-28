#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    char* username = getenv("USER");

    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == -1)
    {
        printf("hiba\n");
    }
    
    printf("%s@%s\n", username, hostname);

    return 0;
}