#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

#define MAXWORD 100

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

#define NKEYS (sizeof keytab / sizeof(keytab[0]))

int getword(char *, int);

int main()
{
    struct tnode *root;
    char word[MAXWORD];
    
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (!isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return EXIT_SUCCESS;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
       ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if(!isalnum((*w = getch()))) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}


#define BUFSIZE 100

static char buf[BUFSIZE]; /* buffer for getch() */
static int bufp = 0; /* next free position in buf*/

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();    
}

void ungetch(int c)
{
    if (bufp < BUFSIZE)
        buf[++bufp] = c;
    else
        fprintf(stderr, "buffer full\n");
}
