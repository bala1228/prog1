#include <stdio.h>
#include <time.h>

int main()
{
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);

    int sec_left = 60 - local_time->tm_sec;
    printf("%d\n", sec_left);

    return 0;
}