#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void file_writing(int test[], int size)
{
    FILE *f = fopen("numbers.txt", "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(f, "%d\n", test[i]);
    }
    
}

int main()
{
    // Változók
    const int size = 100;
    int min = 10;
    int max = 99;
    int i, temp;

    int test[size];

    for (temp = 0, i = min; temp < size; temp++, i++)
    {
        test[temp] = (rand() % (max - min + 1)) + min;
    }

    srand(time(NULL));
    
    // Fisher–Yates keverés algoritmus
    for (i = size - 1; i > 0; i--)
    {
        // Random index
        int r = rand() % i;
        // számok keverése
        temp = test[i];
        test[i] = test[r];
        test[r] = temp;
    }
    for (i = 0; i < size; i++)
    {
        printf("%d ", test[i]);
    }
    puts("");
    
    file_writing(test, size);

    FILE *f = fopen("numbers.txt", "w");
    fwrite(test, sizeof(int), sizeof(size), f);




    return 0;
}
