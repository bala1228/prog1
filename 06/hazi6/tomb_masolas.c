#include <stdio.h>
#include <stdlib.h>

// Kiírja egy tömb tartalmát.
void tomb_kiir(const int tomb_meret, const int tomb[])
{
    for (int i = 0; i < (tomb_meret - 1); i++)
    {
        printf("%d, ", tomb[i]);
    }
    printf("%d", tomb[tomb_meret - 1]);
    puts(" ");
}

// Feltölt egy másolat tömböt az eredeti tömb értékeinek abszolútértékével.
void tomb_masolo_abs(const int meret, const int tomb_eredeti[], int tomb_masolat[])
{
    for (int i = 0; i < meret; i++)
    {
        tomb_masolat[i] = abs(tomb_eredeti[i]);
    }
}

// Egész számokat olvas be és tárol el egy tömbben.
void tomb_fill(const int tomb_meret, int tomb[])
{
    for (int i = 1; i <= tomb_meret; i++)
    {
        printf("%d. szám: ", i);
        scanf("%d", &tomb[i - 1]);
    }
    puts("");
}

int main()
{   
    int tomb_meret = 0;
    
    printf("Hány db számot szeretnél bevinni?\n");
    scanf("%d", &tomb_meret);

    int tomb[tomb_meret];
    int tomb_masolat[tomb_meret];

    tomb_fill(tomb_meret, tomb);   
    tomb_masolo_abs(tomb_meret, tomb, tomb_masolat);
    
    printf("A bevitt számok abszolútértékei: "); 
    tomb_kiir(tomb_meret, tomb_masolat);
    
    printf("A megadott számok: ");
    tomb_kiir(tomb_meret, tomb); 

    return 0;
}