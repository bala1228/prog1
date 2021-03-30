/*
Írjunk egy programot, ami bekéri egy kör sugarát (egész érték), majd írassuk ki a kör kerületét, területét. 
A kerület és terület kiszámítását függvénnyel oldjuk meg!
*/

#include <stdio.h>		//feladat leírása első 4 sorban screenshot miatt
#include <math.h>

double get_kerulet(int r)
{
    double kerulet = 2 * r * M_PI;

    return kerulet;
}


double get_terulet(int r)
{
    double terulet = r * r * M_PI;
    
    return terulet;
}

int main()
{
    int sugar;		//nem cukor!
    do
    {
        printf("Adja meg a kör sugarát! (Egész érték)\n");
        scanf("%d", &sugar); 
        
    } while (sugar <= 0);
    
    
    printf("A kerület: %lf", get_kerulet(sugar));
    printf("\n");
    printf("A kör területe: %lf", get_terulet(sugar));
    printf("\n");

    return 0;

}
