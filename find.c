#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char *line, int max);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    unsigned int lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-') /* [] binds tighter than * and ++ ; here we're indexing the first character of the optional argument string */
        while ((c = *++argv[0])) /* incrementing the pointer argv[0] as to look at what optional argument the user specified */
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (get_line(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) { /* highlighting this */
                if (number)
                    printf("%u:", lineno);
                printf("%s", line);
                found++;
            }
        }
    printf("%d\n", found);
    return found;
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
