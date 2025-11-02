#include <stdio.h>
#include <stdlib.h>

int main() {

    int age = 30;
    int * pAge = &age; // created a Pointer variable 

    printf("age  : %d\n", age);
    printf("age address : %p\n", &age);
    printf("dereferenced age (*&age): %d\n", *&age);
    
    printf("int * pAge = &age\n");
    printf("pAge : %d\n", *pAge); // dereferencing the pointer with *
    
    return 0;
}