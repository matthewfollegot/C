# C

### Notes to self
<details>
    <summary>
<i>Conflicting types error, previous implicit declaration</i>
    </summary><br>

```
error: conflicting types for "<function_name>"
error: previous implicit declaration of "<function_name>"
```
How to solve: Split the declaration from the definition

add function declaration to header file (`.h`) extension and include the file
```c
#include "headers.h"
```
</details>

<details>
    <summary>
<i>Reusing code in multiple files</i>
    </summary><br>

Example: having a script that encrypts <i>some</i> data

creating file `encrypt.h` that may have the following function declaration:
```c
void encrypt(char *message);
```

include `encrypt.h` in the program

Now, when compiling, we can pass more than file to compile:
```
gcc -Wall file.c encrpyt.c -o <output-path>
```
</details>

<details>
    <summary>
<i>Data Types and Sizes</i>
    </summary><br>
`char`      a single byte (8 bits - therefore up to 255)
`int`       16 bits if <b>short</b>, 32 if <b>long</b>
`float`     single-precision floating point
`double`    double-precision floating point
`unsigned`  may be applied to `char` or any integer and obey the laws of the arithmetic module <i>2^n</i>, n being the number of bits. Unsigned are always positive so their max would be 2x the max of their signed counterpart, i.e.:
```
unsigned char (8 bits) have values between 0 and 2^8 = 255 while signed char (8 bits) have values between -128 and 127
``` 

see `<limits.h>` for more details
</details>


<details>
    <summary>
<i>Use braces in nested if statements</i>
    </summary><br>

Example: the indentation in the following code block leads us to believe that the `else` belongs to the first `if`, however, due to the use (or lack) of braces, the compiler will associate the `else` with the inner `if`.

```c
if (n > 0)
    for (i = 0; i < n; i++)
        if (s[i] > 0) {
            printf("...");
            return i;
        }
else /* WRONG */
    printf("error -- n is negative\n");
```

</details>

<details>
    <summary>
<i>Pointers to Functions</i>
    </summary><br>
<h4>Simple Examples</h4>
`int *f();` - f is a function that returns a pointer to an int
`int (*pf)()` - pf is a <b>pointer</b> to a function that returns an int
<b>Explanation:</b> `*` is a prefix operator and it has lower precedence than `()`, so parentheses are necessary to force the proper association.
<h4>More Complex Examples as Function Arguments</h4>
`int (*comp)(void *, void *)` comp is a pointer to a function that takes two pointers of any type as arguments and returns an int
Here is how we can use it:
```quicksort((void**) lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : strcmp));```
We can adapt our `quicksort` function to compare numerically or lexicographically, where numeric is 1 if the user specifies to sort numerically, 0 to sort lexicographically.
We can invoke one of `numcmp` or `strcmp` in `quicksort` like so:
```if ((*comp)(v[i], v[left]) < 0)```
