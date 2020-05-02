#include <stdio.h>
#include <stdlib.h>

/* cat: concatenate files to stdout */
int main(int argc, char *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);

    if (argc == 1) /* no args; copy standard input */
        filecopy(stdin, stdout);
    else {
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: %s: No such file or directory\n", *argv);
                return EXIT_FAILURE;
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        return EXIT_SUCCESS;
    }
}

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while((c = getc(ifp)) != EOF)
        putc(c, ofp);
}
