#include <stdio.h>

int main()
{
    /*
        Írjunk egy programot, amely beolvas két pozitív egész számot (n1 és n2), 
        majd a program írja ki azt a relációs jelet, amit a két érték közé helyezhetünk (<, > vagy
        =)!
    */    
    
    int n1;
    int n2;
    
    //n1 beolvasása
    printf("n1: ");
    scanf("%d", &n1);
    
    //n2 beolvasása
    printf("n2: ");
    scanf("%d", &n2);
    
    printf("\n");

    if (n1 > n2)
    {
        printf(">\n");
    }
    else if (n1 < n2)
    {
        printf("<\n");
    }
    else
    {
        printf("=\n");
    }
    
    return 0;
}
