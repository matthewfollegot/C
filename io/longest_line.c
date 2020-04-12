#include <stdio.h>

#define MAXLINE 1000    /* maximum input line length */

/* using global variables in this implementation */
int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

/* print longest input line; specialized version */
main()
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while((len = get_line()) > 0)
        /* if multiple lines have the same length, the first one parsed will be 'longest' */
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0)
        printf("%s\n", longest);
    return 0;
}

int get_line(void)
{
    /* we keep writing the same array and rely on '\0' to cut off lines shorter than previous line */
    extern char line[];
    int c, i;

    for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
        printf("%s\n", line);
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

void copy(void)
{
    int i;
    extern char line[], longest[];
    
    i = 0;
    while((longest[i] = line[i]) != '\0')
        ++i;
}


// #include <stdio.h>
// #define MAXLINE 1000         /* maximum input line length */

// int get_line(char line[], int maxline);
// void copy(char to[], char from[]);

// main()
// {
//     int len;
//     int max;
//     char line[MAXLINE];      /* current input line */
//     char longest[MAXLINE];   /* longest line saved here */

//     max = 0;
//     while ((len = get_line(line, MAXLINE)) > 0)
//         if (len > max) {
//             max = len;
//             copy(longest, line);
//         }
//     if (max > 0)
//         printf("%s", longest);
//     return 0;
// }

// /* get_line: read a line into s, return length */
// int get_line(char s[], int lim)
// {
//     int c, i;
    
//     for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
//         s[i] = c;
//     if(c == '\n') {
//         s[i] = c;
//         ++i;
//     }
//     s[i] = '\0';
//     return i;
// }

// /* copy: copy 'from' to 'to'; assume to is big enough */
// void copy(char to[], char from[])
// {
//     int i;

//     i = 0;
//     while ((to[i] = from[i]) != '\0') /* this is cool, I didn't assignment returned the assigned value, doesn't happen in Python */
//         ++i;
// }
