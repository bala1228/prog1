#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t current_time;
    struct tm *timeinfo;
    int current_min;

    current_time = time(NULL);
    timeinfo = localtime(&current_time);

    current_min = timeinfo->tm_min;

    srand(current_min);

    printf("%d\n", (rand() % 1000000));

    return 0;
}