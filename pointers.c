#include <stdio.h>

int main() {

    char * name = "Matthew";
    printf("%c\n", name[0]);

    int a = 1;
    int * pointer_to_a = &a;
    // these are the same
    printf("address of a is %x\n", pointer_to_a); 
    printf("address of a is %x\n", &a);

    a+=1;
    printf("The value a is %d\n", a);
    printf("The value of a is %d\n", *pointer_to_a);
    
    *pointer_to_a += 1;
    printf("The value of a is %d\n", *pointer_to_a);

    int array[5];
    int *ptr = array; // same as *ptr = &array[0]
    int num = 2;

    for(;ptr<&array[5];ptr++) {
        *ptr = num;
        num *= num;
    }

    for(int i = 0; i < 5; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}