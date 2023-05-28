#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    int numbers[35] = { 0 };
    int randindex;
    int counter = 7;
    
    do
    {
        randindex = rand() % 35 - 1;
        if (numbers[randindex] == 0)
        {
            numbers[randindex] = 1;
            counter--;
        }
        
    } while (counter);
    
    
    for (int i = 0; i < 35; i++)
    {
        if (numbers[i] == 1)
        {
            printf("%d ", i + 1);
        }
    }
    puts("");
    
    return 0;
}