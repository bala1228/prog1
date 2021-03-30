#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Pont;

double distance(Pont p1, Pont p2)
{
    double d, a, b;
    a = ((p2.x - p1.x) * (p2.x - p1.x));
    b = ((p2.y - p1.y) * (p2.y - p1.y));
    d = sqrt(a + b);
    
    printf("a: %lf, b: %lf, d: %lf\n", a, b, d);

    return d;
}

int main()
{
    Pont a = { 1, 2 };
    Pont b = { 6, 5 };

    printf("A két pont közti távolság: %lf\n", distance(a, b));

    return 0;
}