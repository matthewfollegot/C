#include <stdio.h>
#include <string.h>

int main() {

    /* Defining strings */
    
    // using pointer - cannot manipulate
    char * name = "Matthew";
    printf("%s\n", name); // string formatting with printf

    // char array - can manipulate
    char name2[] = "Matthew";
    
    /* String length */
    printf("%lu\n", strlen(name2)); // 7 not 6 because of terminating character at the end of strings in C
    
    /* Comparison of strings */
    if (strncmp(name, "Matt", 4) == 0) { // passes
        printf("Hello Matt!\n");
    } else {
        printf("Go away!\n");
    }
    
    
    /* Concatenation of strings */
    char dest[20]="Hello";
    char src[20]="World";
    strncat(dest,src,3);
    printf("%s\n",dest);
    strncat(dest,src,20);
    printf("%s\n",dest);

    return 0;

}