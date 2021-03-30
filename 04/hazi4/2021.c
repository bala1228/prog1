#include <stdio.h>
#include <stdlib.h>

int main()
{
    char elso = 'W', masodik = 'X', harmadik = 'C', negyedik = '(';
    int vegso_allomas = masodik - negyedik;

    printf("%d%d\n", elso - harmadik, masodik - harmadik);

    exit(vegso_allomas);
}