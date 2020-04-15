#include <stdio.h>
#include <string.h>
#include <ctype.h>

int any(char s1[], char s2[]);
int atoi(char s[]);
void expand(char s1[], char s2[]);
void itoa(int n, char s[]);
int lower(int c);
void reverse(char s[]);
void strconcat(char s[], char t[]);
void squeeze2(char s1[], char s2[]);

int main()
{

    char s1[] = "bcdea";
    char s2[] = "efag";

    printf("%d\n", any(s1, s2)); // prints 3; e is the first occurence of s1 that occurs in s2
    printf("%d\n", any("abcedf\thijk", "lmnopqrst\t")); // prints 6 ('\t')

    printf("before squeeze %s\n", s1); // prints bcdea
    
    squeeze2(s1, s2);
    printf("after squeeze %s\n", s1); // prints bcd

    char nombre[10] = "Matt";
    printf("before concat: %s\n", nombre);

    strconcat(nombre, "hew");
    printf("after concat: %s\n", nombre); //prints Matthew

    printf("atoi: %d\n", atoi("   +12345"));
    printf("%c\n", lower('Z'));
    
    printf("%zu\n", strnlen("matt", 100));

    reverse(nombre);
    printf("Matthew reversed is %s\n", nombre);

    char nums[10];
    int n = -777;
    itoa(n, nums);
    printf("%d to int: %s\n", n, nums);

    char to_expand[] = "a-z";
    char expanded[100];
    expand(to_expand, expanded);
    printf("%s expanded: %s\n", to_expand, expanded);

    return 1;
}

/* atoi: converts string of digits to integer; version 2 */
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-' ? -1 : 1);
    if (s[i] == '+' || s[i] == '-') /* skip sign */
        i++;
    for(n = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

/* strconcat: concatenates t to the end of s; s must be long enough */
void strconcat(char s[], char t[])
{
    int i, j;
    i = j = 0;

    while (s[i] != '\0')
        ++i;
    while ((s[i++] = t[j++]) != '\0')
        ;
}

/* squeeze: alternate to squeeze that removes any characters in s1 that appear in s2 */
void squeeze2(char s1[], char s2[])
{
    int i, j, k;
    
    j = 0;
    for (i = 0; s1[i] != '\0'; i++)
    {
        for (k = 0; (s2[k] != s1[i]) && s2[k] != '\0'; k++) // first condition is similar to doing a check and adding a break;
            ;
        if (s2[k] == '\0') // character at s1[i] wasn't found in s2 (we reached the end of s2)
            s1[j++] = s1[i]; 

    }
    s1[j] = '\0';
}

/* any: returns the first location of s1 where any character in s2 occurs, or -1 if no character in s1 occurs in s2. */
/* strpbrk does the same job but returns a pointer instead */
int any(char s1[], char s2[])
{
    int i, j;

    for(i = 0; s1[i] != '\0'; i++)
    {
        for(j = 0; s2[j] != '\0'; j++)
        {
            if (s2[j] == s1[i])
                return i;
        }
    }
    return -1;
}

/* reverse: reversing a string in-place */
void reverse(char s[])
{
    int c, i, j;
    for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c; // could reduce these three assignments to a single line, separated by commas
    }
}

/* itoa: converts n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
    
}

/* expand: expands shorhand notations in s1 to the equivalent complete list in s2 (i.e. a-d to abcd) */
void expand(char s1[], char s2[])
{
    int i, j;

    /* if (s1[0] == '-') {
        char runner;
        while (runner != stopper)
            ;
    } */

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        s2[j++] = s1[i];
        if (s1[i+1] == '-') {
            ++i;
            char runner = s1[i-1]+1;
            while (runner < s1[i+1])
                s2[j++] = runner++;
        }
        
        s2[j++] = s1[++i];
    }
    s2[j] = '\0';



}
