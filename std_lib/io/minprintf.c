#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

int main()
{
    char *greeting = "hello there";
    int age = 20;
    minprintf("%s, i am %d years old", greeting, age);

    return EXIT_SUCCESS;
}

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg */
    char *p, *sval;
    int ival;
    double dval;
    
    va_start(ap, fmt); /* make ap point to first unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    printf("\n");
    va_end(ap); /* clean up when done */
}
