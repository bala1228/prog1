#include <stdio.h>

//int main()
//{
    //int pontok[20];
//
    //pontok[0] = 4;
    //printf("%d", pontok[0]);
    //printf("\n");

    //int t1[3] = { 1, 2, 3};
    //int t2[3];
    //
    //for (int i = 0; i < 3; i++)
    //{
    //    t2[i] = t1[i];
    //}
    //
    //for (int i = 0; i < 3; i++)
    //{
    //    printf("%d\n", t2[i]);
    //}
//    
void set_int(int x)
{
    x = 42;
}

void set_array(int array[])
{
    array[0] = 22;
}

int main()
{
    int a = 10;
    int b[4] = { 0, 1, 2, 3 };
    set_int(a);
    set_array(b);
    printf("%d, %d\n", a, b[0]);

    return 0;
}