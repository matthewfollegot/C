#include <stdio.h>
#include <string.h>
#include "extras.h"
/* compile with storage_allocator.c */

#define MAXLINES 5000 /* max #lines to be stored */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void quick_sort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);

/* sort input lines */
int main()
{
    int nlines; /* # of input lines read */

    if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        quick_sort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
int get_line(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcopy(p, line);
            lineptr[nlines++] = p; /* getting lineptr indices to hold pointers */
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while(--nlines > 0)
        printf("%s\n", *lineptr++);
}

/* quick_sort: sort v[left], v[right] into increasing order */
void quick_sort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)
        return; /* do nothing if array contains less than 2 elements */
    swap(v, left, (left + right) / 2); /* move partition elem to v[0] */
    last = left;
    for (i = left + 1; i <= right; i++) /* partition */
        if (strcompare(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    quick_sort(v, left, last-1);
    quick_sort(v, last+1, right);
}

/* swap: interchange v[i] with v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int get_line(char *s, int lim)
{
    int c;
    char *t = s;

    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';

    return s-t;
}
