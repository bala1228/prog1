#include <stdio.h>

int main()
{
    //írassuk ki a számokat 10-1-ig csökkenő sorrendben (zárt intervallum)
    for (int i = 10; i >= 1; i--)
    {
        printf("%d\n", i);
    }
    
    printf("------------------------------------------------\n");

    //ugyanez while ciklussal
    int j = 10;
    while (j >= 1)
    {
        printf("%d\n", j);
        j--;
    }
    
    
    
    return 0;
}