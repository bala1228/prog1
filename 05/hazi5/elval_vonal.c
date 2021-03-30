#include <stdio.h>

void line(char c, int length)
{    
    while (length > 0)
    {
        printf("%c", c);
        length--;
    }
    puts("");
}

int main()
{
    puts("Hello");
    line('-', 5);
    puts("World");

    return 0;
}
