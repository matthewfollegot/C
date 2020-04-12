#include <stdio.h>

int power(int base, int n);

main() 
{
    /* optimize by getting user input when we get to that part */
    printf("%d\n", power(2, 5));
}

int power(int base, int n)
{
    int i;
    for (i = 1; n > 0; --n)
        i *= base;
    return i;
}
