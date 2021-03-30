#include <stdio.h>
#include <unistd.h>

int main()
{
    int i = 1;

    while (1)
    {
        printf("%d\n", i);
        i = i * 2;

        sleep(1);
    }
    
    
    return 0;
}