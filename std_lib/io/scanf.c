#include <stdio.h>

int main() /* rudimentary calculator to illustrate scanf */
{
    double sum, v;

    while (scanf("%lf", &v) == 1) /* returns 1 if one value is converted (successful) */
        printf("\t%.2f\n", sum += v);
    
    return 0;
}
