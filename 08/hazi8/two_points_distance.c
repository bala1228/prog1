#include <stdio.h>
#include <math.h>

typedef struct 
{
    int x;
    int y;
} Pont;

double distance(Pont p1, Pont p2)
{
    double distance;
    distance = sqrt(((p2.y - p1.y) * (p2.y - p1.y)) + ((p2.x - p1.x) * (p2.x - p1.x)));

    return distance;
}

int main()
{
    Pont a = { -4, 5 };
    Pont b = { 7, 15 };

    printf("A két pont közti távolság: %lf\n", distance(a, b));

    return 0;
}
