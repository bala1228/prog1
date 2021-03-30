#include <stdio.h>

void hello(const int n)
{
    for (int i = 0; i < n; i++)
    {
        puts("hello");
    }
    
}

int main()
{
    hello(5);

    return 0;
}