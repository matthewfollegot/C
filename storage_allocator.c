#include <stdio.h>

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else   /* not enough room */
        return 0; /* C guarantees that zero is never a valid address for data, so we can use it to signal no space */
}

void afree(char *p) /* free storage pointed to by p */ 
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
