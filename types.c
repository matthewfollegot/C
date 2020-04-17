#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int any(char s1[], char s2[]);
int atoi(char s[]);
double atof(char s[]);
void expand(char s1[], char s2[]);
void itoa(int n, char s[]);
void ritoa(int n, char s[]);
int lower(int c);
void reverse(char *s);
void strconcat(char s[], char t[]);
int strlength(char *s);
void squeeze2(char s1[], char s2[]);
int trim(char s[]);

int main()
{
    double atof(char []); /* tells the calling routine that atof returns a non-int value */
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
    char rnums[10];
    int n = -777;
    int rn = -555;
    itoa(n, nums);
    ritoa(rn, rnums);
    printf("%d to int using itoa: %s\n", n, nums);
    printf("%d to int using ritoa: %s\n", rn, rnums);

    char to_expand[] = "-m-z0-5";
    char expanded[100];
    expand(to_expand, expanded);
    printf("%s expanded: %s\n", to_expand, expanded);

    char to_trim[] = "hello world  \n \t";
    printf("string that will be trimmed starts here %s and ends here\n", to_trim);
    n = trim(to_trim);
    printf("trim() returned %d and to_trim is now %s\n", n, to_trim);

    char to_double[] = "-777.777";
    printf("%s to double: %f\n", to_double, atof(to_double));

    printf("length of string: %d\n", strlength(to_double));

    return 1;
}

/* atoi: converts string of digits to integer; version 2 */
int atoi(char s[])
{
    double atof(char s[]); /* don't need this, but keeping as an example */

    return (int) atof(s);
}

/* atof: converts string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
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
void reverse(char *s)
{
    char *p1 = s;
    char *p2 = s + strlength(s) - 1;

    while (p1 < p2) {
        char tmp = *p1;
        *p1++ = *p2;
        *p2-- = tmp;
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

/* ritoa: recursive version of itoa */
void ritoa(int n, char s[])
{
    static int i = 0; /* i is static so that it doesn't get reinitialized for every subsequent function call */

    if (n / 10)
        ritoa(n/10, s);
    else {
        if (n < 0)
            s[i++] = '-';
    }
    
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}

/* expand: expands shorthand notations in s1 to the equivalent complete list in s2 (i.e. a-d to abcd) */
void expand(char s1[], char s2[])
{
    int i, j, c;

    i = j = 0;
    while ((c = s1[i++]) != '\0')
        if (s1[i] == '-' && s1[i+1] >= c)
        {
            i++;
            while(c < s1[i])
                s2[j++] = c++;
        }
        else
            s2[j++] = c;

    s2[j] = '\0';
}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
    int n;

    for (n = strlength(s)-1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n+1] = '\0';
    return n;
}

/* strlength: return length of string s */
int strlength(char *s)
{
    char *p = s;
    while (*p != '\0')
        p++;

    return p - s;
}
