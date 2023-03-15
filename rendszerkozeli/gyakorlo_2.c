#include <stdio.h>
#include <string.h>

//Írj egy programot, amely (visszatérési értékként) visszaadja az operációs rendszer számára annak a
//parancsnak a karakterszámát white space-ek nélkül, ami őt magát elindította! (Például a 12-t a
//”./a.out Hello” parancs esetén.)

int main(int argc, char* argv[])
{
    int counter = 0;
    
    for (int i = 0; i < argc; i++)
    {
        counter += strlen(argv[i]);
    }
    
    printf("Karakterek száma: %d\n", counter);

    return 0;
}