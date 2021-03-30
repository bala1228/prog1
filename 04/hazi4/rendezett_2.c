#include <stdio.h>

void tomb_kiir(int m, const int tomb[])
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ", tomb[i]);
    }
    puts(" ");      //printf("\n");
}

int rendezett(int meret, int tomb[])
{
    for (int i = 1; i < meret; i++)
    {
        for (int j = meret - 1; j >= i; j--)
        {
            if (tomb[j-1] > tomb[j])
            {
                //szükség lenne rendezésre, tehát nem rendezett
                return 0;   
            }   
        }   
    }
    
    //nincs szükség rendezésre, tehát rendezett
    return 1;   
}

int main()
{
    int tomb_1[10] = { 156, 455, 4, 54, 489, 9 , 9, 32, 5, 5667 };
    //int tomb_1[10] = { 1, 2, 3, 4, 5, 6, 7, 9, 9, 10 };
    int meret_tomb_1 = 10;

    puts("Tömb:");
    tomb_kiir(meret_tomb_1, tomb_1);

    printf("Rendezett: %s\n", rendezett(meret_tomb_1, tomb_1) ? "igen" : "nem");

    return 0;
}
