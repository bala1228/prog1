#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int output = 1000;

    srand(time(NULL));

    int num[] = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    int length = (sizeof(num)) / sizeof(num[0]);

    for (int i = 0; i < output; i++)
    {
        printf("%d", num[rand() % length - 1]);
    }
    
    puts("");

    return 0;
}