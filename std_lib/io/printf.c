#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = "hello, world";

    printf(":%%s: \t\t :%s:\n", str);
    printf(":%%10s: \t\t :%10s:\n", str);
    printf(":%%15s: \t\t :%15s:\n", str);
    printf(":%%.10s: \t :%.10s:\n", str);
    printf(":%%.15s: \t :%.15s:\n", str);
    printf(":%%-10s: \t :%-10s:\n", str);
    printf(":%%-15s: \t :%-15s:\n", str);
    printf(":%%15.10s: \t :%15.10s:\n", str); 
    /* -15 represents minimum field width with left adjustment (-), whereas the period separates the field width from the precision and 10, the precision, specifies the max number of characters to be printed out */
    printf(":%%-15.10s: \t :%-15.10s:\n", str);

    return EXIT_SUCCESS;
}
