#include <stdio.h>
#include <string.h>

#define SIZE 100

int input_and_counting(char text[])
{
    // Ebben a változóban tároljuk hányszor futott le a ciklus.
    // -1 az, különben a '*' is bel lenne számolva.
    int counter = -1;
    // Ebben a változóban tároljuk a leghosszabb string hosszát.
    int length_max = -1;
    
    while (1)
    {
        int temp = 0;
        
        // Ha '*' karakter kerül a string-be, akkor megáll a bevitel,
        // kiiírja hány szót kapott bevitelnek és hány karakter a leghosszabb.
        if (strchr(text, '*') != NULL)
        {
            printf("%d szót adtál meg. ", counter);
            printf("A leghosszabb szó %d karakterből áll.\n", length_max);
            break;
        }
        else
        {
            printf("Szó: ");
            fgets(text, SIZE, stdin);
            text[strlen(text) - 1] = '\0';
            temp = strlen(text);
            counter++;
            
            if (temp > length_max)
            {
                length_max = temp;
            }
        }
    }
}

int main()
{
    char text[SIZE];

    printf("Adj meg szavakat '*' végjelig!\n");

    input_and_counting(text);

    return 0;
}
