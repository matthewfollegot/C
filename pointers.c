#include <stdio.h>
#include "reverse_polish_calculator/getch.c"

int getint(int *);
void swap(int *px, int *py);

int main() {
   
    /* swapping by reference */
    int x = 1, y = 2;
    printf("x: %d\t y: %d\n", x, y);
    swap(&x, &y);
    printf("x: %d\t y: %d\n", x, y);

    int array[] = { 1, 2, 3, 4, 5 };
    printf("array[2] = %d\n", array[2]);
    getint(&array[2]);
    printf("array[2] = %d\n", array[2]);

    return 0;
}

/* swap: swapping elements by referene instead of by value */
void swap(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}


#include <ctype.h> 

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* not a number */
        return 0;
    }
   
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for(*pn = 0; isdigit(c); c = getch()) /* skip if c is not a digit */
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;

    if (c != EOF)
        ungetch(c); /* unget non-digit */
    return c;
}
