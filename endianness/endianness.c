#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t i = 1;
    // Using a char pointer to an int will enable us to look at the
    // value of its bytes.
    char *p = (char *)&i;

    /* 1 (as a 32 bit unsigned integer) is represented as 01 00 00 00 on EL
     * systems, and 00 00 00 01 on EB systems. We just check the value of the
     * first byte in memory, which should be equal to 1 on EL systems and 0 on
     * EB systems.
     */
    if (p[0] == 1)
        puts("LittleEndian");
    else
        puts("BigEndian");

    return 0;
}
