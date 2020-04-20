#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extras.h"

#define MAXLINES 5000 /* max #lines to be stored */

char *lineptr[MAXLINES]; /* pointers to text lines */
char linestor[MAXLINES];

int readlines(char *lineptr[], char *linestor, int nlines);
void writelines(char *lineptr[], int nlines);
void quick_sort(void *lineptr[], int left, int right, int (*comp)(void *, void*));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* # of input lines read */
    int numeric = 0; /* 1 if numeric sort */

    if (argc > 1 && strcompare(argv[1], "-n") == 0)
        numeric = 1;
    if((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0) {
        quick_sort((void**) lineptr, 0, nlines-1, (int (*) (void *, void *)) (numeric ? numcmp : strcompare));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
#define MAXSTOR 5000

int get_line(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p+len > linestop)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcopy(p, line);
            lineptr[nlines++] = p; /* getting lineptr indices to hold pointers */
            p += len;
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
void quick_sort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int i, int j);

    if (left >= right)
        return; /* do nothing if array contains less than 2 elements */
    swap(v, left, (left + right) / 2); /* move partition elem to v[0] */
    last = left;
    for (i = left + 1; i <= right; i++) /* partition */
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    quick_sort(v, left, last-1, comp);
    quick_sort(v, last+1, right, comp);
}

/* swap: interchange v[i] with v[j] */
void swap(void *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* get_line: gets the length of a line using a pointer to an array that has a length of the max line length */
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

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}
