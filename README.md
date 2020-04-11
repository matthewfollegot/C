# C

### Notes to self
<details>
    <summary>
Conflicting types error, previous implicit declaration
    </summary>

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
Reusing code in multiple files
    </summary>

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