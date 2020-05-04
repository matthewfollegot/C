#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void line_diff(char *l1, char *l2, int line_no)
{
    if (strcmp(l1, l2) != 0)
        printf("%d: %s\n%d: %s", line_no, l1, line_no, l2);
}

int main(int argc, char *argv[])
{
    FILE *f1;
    FILE *f2;

    if (argc != 3) {
        printf("compare: Usage compare file1 file2\n");
        return 1;
    }
    else {
        if ((f1 = fopen(*++argv, "r")) == NULL) {
            fprintf(stderr, "%s: can't open %s\n", argv[0], *argv);
            exit(1);
        }
        if ((f2 = fopen(*++argv, "r")) == NULL) {
            fprintf(stderr, "%s: can't open %s\n", argv[0], *argv);
            exit(1); 
        }
    }
    
    char line_ptr1[MAXLINE];
    char line_ptr2[MAXLINE];
    
    int line_no = 1;
    while ((fgets(line_ptr1, MAXLINE, f1) != NULL) && (fgets(line_ptr2, MAXLINE, f2) != NULL)) {
        line_diff(line_ptr1, line_ptr2, line_no);
        line_no++;
    }

    fclose(f1);
    fclose(f2);
    exit(0);
}
