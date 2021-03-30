#include <stdio.h>

void tomb_kiir(int m, const int tomb[])
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ", tomb[i]);
    }
    puts(" ");      //printf("\n");
}

void rendezes_buborek(int meret, int tomb[])
{
    for (int i = 1; i < meret; i++)
    {
        for (int j = meret - 1; j >= i; j--)
        {
            if (tomb[j - 1] > tomb[j])
            {
                int tmp = tomb[j - 1];
                tomb[j - 1] = tomb[j];
                tomb[j] = tmp;
            }   
        }   
    }
}

void rendezes_kivalasztasos(int meret, int tomb[])
{
    for (int i = 0; i < (meret - 1); i++)
    {
        int min = i, tmp;
        for (int j = i + 1; j < meret; j++)
        {
            if (tomb[i] < tomb [min])
            {
                min = i;
                tmp = tomb[i];
                tomb[i] = tomb[min];
                tomb[min] = tmp;
            } 
        } 
    }
}

int tomb_masolo(const int meret, const int tomb_eredeti[], int tomb_masolat[])
{
    for (int i = 0; i < meret; i++)
    {
        tomb_masolat[i] = tomb_eredeti[i];
    }

    return tomb_masolat[meret];
}

int osszehasonlito(const int meret, const int tomb_eredeti[], const int tomb_masolat[])
{
    for (int i = 0; i < meret; i++)
    {
        if (tomb_eredeti[i] != tomb_masolat[i])
        {
            return 0;
        } 
    }
    
    return 1;
}

int main()
{
    //int tomb_1[10] = { 156, 455, 4, 54, 489, 9 , 9, 32, 5, 5667 };
    int tomb_1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int meret_tomb_1 = 10;
    int tomb_masolat[10];
    tomb_masolo(meret_tomb_1, tomb_1, tomb_masolat);

    puts("Tömb:");
    tomb_kiir(meret_tomb_1, tomb_1);
    
    rendezes_buborek(meret_tomb_1, tomb_masolat);

    puts("--------------------------------------------------------------------------------");

    puts("Tömb:");
    tomb_kiir(meret_tomb_1, tomb_1);

    rendezes_kivalasztasos(meret_tomb_1, tomb_1);

    puts("Tömb:");
    tomb_kiir(meret_tomb_1, tomb_1);
    puts("--------------------------------------------------------------------------------");

    int eredmeny = osszehasonlito(meret_tomb_1, tomb_1, tomb_masolat);

    printf("Rendezett: %s\n", eredmeny ? "igen" : "nem");

    return 0;
}
