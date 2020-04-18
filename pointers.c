#include <stdio.h>
#include "reverse_polish_calculator/getch.c"

int getint(int *);
void strconcat(char *s, char *t);
int strcompare(char *s, char *t);
void strcopy(char *s, char *t);
int strending(char *s, char *t);
void swap(int *px, int *py);

int main() {
   
    char pname[] = "Hello World";
    char pcpy[15];
    strcopy(pcpy, pname);
    printf("%s\n", pcpy);
    
    pname[5] = 'x';
    printf("%s\n", pname);
    printf("%d\n", strcompare(pname, pcpy));
    
    strconcat(pcpy, "abc");
    printf("%s\n", pcpy);

    char *s = "hello there";
    char *t = "hre";
    printf("does \"%s\" end in \"%s\": %d\n", s, t, strending(s, t));

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

/* strcopy: copies t to s */
void strcopy(char *s, char *t)
{
    while (*s++=*t++);
}

/* strcompare: return -1 if s<t, 0 if s==t, 1 if s>t */
int strcompare(char *s, char *t)
{
    const unsigned char *us = (const unsigned char *) s;
    const unsigned char *ut = (const unsigned char *) t;
    for (; *us==*ut && *us; us++, ut++)
        ;
    return (*us > *ut) - (*us < *ut);
}

/* strconcat: copies string t to the end of s */
void strconcat(char *s, char *t)
{
    while (*s++ != '\0');
    s--; /* we increment passed '\0' due to *s++ (we increment, then dereference the value at the old value of s) */
    while(*s++=*t++);
    *s = '\0';
}

/* strending: returns 1 if t occurs at the end of s, 0 otherwise */
int strending(char *s, char *t)
{
    int len = 0;
    int res;
    while(*s++ != '\0')
        len++;
    s--;

    char *ptr = t;
    while(*t++ != '\0')
        s--;

    res = (strcompare(s, ptr) == 0) ? 1 : 0;
    if (res==1)
        return 1;
    return 0;
}
