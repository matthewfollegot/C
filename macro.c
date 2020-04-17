#include <stdio.h>

#define swap(t,x,y) { t _z; \
                        _z = x; \
                        x = y; \
                        y = _z; }

int main()
{
    char c1 = 'a';
    char c2 = 'b';
    printf("c1 = %c\tc2 = %c\n", c1, c2);
    swap(char,c1,c2);
    printf("c1 = %c\tc2 = %c\n", c1, c2);
}

