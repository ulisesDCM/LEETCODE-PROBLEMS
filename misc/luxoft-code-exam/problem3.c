#include <stdlib.h>
#include <stdio.h>

int copy_bit(int src, int dst, int pos)
{
    // Waiting to be implemented
    int bit_src;
    int ret = dst;

    bit_src = (src & (1<<pos)) >> pos;
    ret &= ~(1<<pos);
    ret |= (bit_src << pos);
    return ret;
}

#ifndef RunTests
int main()
{
    printf("%d", copy_bit(7, 12, 3));
}
#endif