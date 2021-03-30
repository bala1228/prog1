#include <stdio.h>
#include <math.h>
/*
Írjunk egy programot, ami bekéri egy gömb sugarát (valós érték), majd írassuk ki a gömb felszínét és térfogatát. 
Három függvényre is szükség lesz: get_double(), amivel egy valós értéket olvasunk be a billentyűzetről, 
illetve a felszín és térfogat kiszámítását is függvénnyel oldjuk meg!
*/

const double PI = M_PI;

double get_double() //valós érték beolvasására szolgáló függvény
{
    double r;
    
    printf("Adja meg a gömb sugarát!\n");
    scanf("%lf", &r);
    while (1)
    {
        if (r <= 0)
        {
            printf("A megadott szám nem pozitív.\n");  //screeshot miatt 2 sor
            printf("Adjon meg egy pozitív valós számot!\n");
            scanf("%lf", &r);
        }
        else
        {
            break;
        }
    }
    
    return r;
}

double get_felszin(double r)       
{
    double felszin = 4 * r * r * PI;

    return felszin;
}

double get_terfogat(double r)       
{
    double terfogat = (4 * r * r * r * PI) / 3;
    
    return terfogat;
}

int main()
{
    double sugar = get_double();
    
    printf("A kerület: %lf", get_felszin(sugar));
    printf("\n");
    
    printf("A kör területe: %lf", get_terfogat(sugar));
    printf("\n");

    return 0;

}
