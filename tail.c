#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEF_NUM_LINES 10 /* default number of lines to print */
#define MAX_LINE_LEN 1000

char *dupstr(const char *s)
{
    char *p = malloc(strlen(s)-1);
    if (p)
        strcpy(p, s);
    return p;
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


int main(int argc, char *argv[])
{
    int num_lines = DEF_NUM_LINES;
    char buffer[MAX_LINE_LEN];
    char **line_ptrs;
    int i;
    unsigned current_line, j;

    if (argc == 1)
        ;
    else if (argc == 3 && (*++argv)[0] == '-' && (*argv)[1] == 'n') {
        num_lines = atoi((++argv)[0]);
    }
    else
        num_lines = 0;
        printf("Usage: tail [-n] no_lines\n");

    if (num_lines)
        printf("%d\n", num_lines);
    
    /* get enough storage for an array of n pointers */
    line_ptrs = malloc (sizeof *line_ptrs * num_lines);
    if (!line_ptrs) {
        fprintf(stderr, "Out of memory\n");
        return EXIT_FAILURE;
    }
    
    /* make all pointers point to NULL */
    for (int i = 0; i < num_lines; i++)
        line_ptrs[i] = NULL;

    current_line = 0;
    do {
        get_line(buffer, sizeof buffer);
        if (!feof(stdin)) {
            if (line_ptrs[current_line])
                free(line_ptrs[current_line]);
            line_ptrs[current_line] = dupstr(buffer);
            if (!line_ptrs[current_line]) {
                fprintf(stderr, "Out of memory\n");
                return EXIT_FAILURE; 
            }
        current_line = (current_line + 1) % num_lines; /* once we exceed num_lines, we keep overwriting the indices up to num_lines to not give away extra storage */ 
        }
    } while (!feof(stdin));

    /* finished reading the file, ready to print the lines */
    j = current_line;
    for (i = 0; i < num_lines; i++) {
        j = (current_line + i) % num_lines; /* pointer increases past current_line and is 'subtracted' by num_lines */
        if (line_ptrs[j]) {
            printf("%s", line_ptrs[j]);
            free(line_ptrs[j]);
        }
    }

  return EXIT_SUCCESS;
}
