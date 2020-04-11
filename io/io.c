#include <stdio.h>

main()
{
    int c;

    printf("The value of EOF is %d\n", EOF); // works because EOF is an integer

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}