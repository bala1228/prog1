#include <stdio.h>

//négyzet kerölete/területe

int main()
{
    //négyzet oldalainak hossza
    int oldal;
    printf("Mi a négyzet oldalának a hossz? (cm-ben)\n");
    scanf("%d", &oldal);
    
    int kerulet = 4 * oldal;
    int terulet = oldal * oldal;
    
    printf("A négyzet kerülete: %d  cm\n", kerulet);
    printf("A négyzet területe: %d  cm^2\n", terulet);
    return 0;
}
    
