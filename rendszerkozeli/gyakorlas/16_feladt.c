#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int totalCharacters = 1000;
    int spaceCount = totalCharacters / 8; // 1/7 része
    int charCount = totalCharacters - spaceCount;
    int chance = -1;

    for (int i = 0; i < totalCharacters; i++) 
    {
        chance = rand() % 7;
        if (chance == 6 && spaceCount != 0)
        {
            putchar(' ');
            spaceCount--;
        }
        else
        {
            int randomIndex = rand() % (sizeof(alphabet) - 1);
            printf("%c", alphabet[randomIndex]);
        }   
    }

    printf("\n");
    printf("\n#%d\n", spaceCount);

    return 0;
}
