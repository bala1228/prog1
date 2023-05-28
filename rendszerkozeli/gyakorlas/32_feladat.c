#include <stdio.h>

unsigned int reverse_byte_order(unsigned int num)
{
    unsigned int result = 0;
    result |= (num & 0xFF) << 24;
    result |= (num & 0xFF00) << 8;
    result |= (num & 0xFF0000) >> 8;
    result |= (num & 0xFF000000) >> 24;
    
    return result;
}

int main()
{
    unsigned int num = 308276097;
    unsigned int reversed = reverse_byte_order(num);

    printf("#%d\n", num);
    printf("##%u\n", reversed);

    return 0;
}