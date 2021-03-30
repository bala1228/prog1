#include <stdio.h>

float szoroz(float a, float b)
{
    return a * b;
}

float osszeadas(float a, float b)
{
    return a + b;
}

float kivonas(float a, float b)
{
    return a - b;
}

float osztas(float a, float b)
{
    return a / b;
}



int main()
{
    char muvelet;
    float a, b;
    printf("Mi a művelet?\n");
    scanf("%f %c %f", &a, &muvelet, &b);
    
    printf("\n");


    switch (muvelet)
    {
    case '+':
        printf("Eredmény: %f", osszeadas(a, b));
        break;
    case '-':
        printf("Eredmény: %f", kivonas(a, b));
        break;
    case '*':
        printf("Eredmény: %f", szoroz(a, b));
        break;
    case '/':
        printf("Eredmény: %f", osztas(a, b));
        break;
    default:
        printf("Hibás bemenet!");
        break;
    }

    printf("\n");

    return 0;
}