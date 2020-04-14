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
