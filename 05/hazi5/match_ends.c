#include "prog1.h"
#include <stdio.h>
#include <string.h>

/*
Bemenet: sztringeket tartalmazó tömb. Számoljuk meg, hogy a bemenetben
hány olyan sztring van, melynek a hossza legalább 2 s az
első karaktere egyezik az utolsó karakterével. A visszatérési
érték ezen feltételeket kielégítő sztringek száma legyen.

Példák (Python kóddal, majd át kell írni C-be):

match_ends(["aba", "xyz", "aa", "x", "bbb"])    ->  3
match_ends(["", "x", "xy", "xyx", "xx"])        ->  2
match_ends(["aaa", "be", "abc", "hello"])       ->  1
*/

// Megvizsgálja, hogy a string első és utolsó karaktere megegyezik-e.
int first_same_last(string s)
{
    if (s[0] == s[strlen(s) - 1])
    {
        // Igaz
        return 1;
    }

    // Hamis
    return 0;
}

// Megvizsgálja a string-eket hosszuk szerint, majd a másik eljárás
// segítségével eldönti, hogy megegyezik-e az adott string első
// és utolsó karaktere, majd vissadja hány ilyen stringet tartalmaz
// az adott tömb.
int match_ends(int size, string words[])
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        
        if (strlen(words[i]) >= 2)
        {
            if (first_same_last(words[i]) > 0)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    string szavak1[] = { "aaa", "be", "abc", "hello" };
    int szavak1_meret = 5;

    printf("2 karakter es annal hosszabb szavak, amelyek elso es ");
    printf("utolso karaktere megegyezik: %d\n", match_ends(szavak1_meret, szavak1));

    for (int i = 0; i < szavak1_meret; ++i)
    {
        puts(szavak1[i]);
    }

    return 0;
}
