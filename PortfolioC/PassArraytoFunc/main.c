#include <stdio.h>
#include <stdlib.h>

// Passing an array to a Function

void add(int *x);
void array_add(int array[], int size);

int main() {

    int a = 5;
    add(&a);
    printf("a: %d\n", a);

    int myarray[] = {1,2,3,4,5,6,7,8,9,20,31,42,53,64,100};
    int length = sizeof(myarray) / sizeof(myarray[0]);
    
    printf("Original array : ");
    for (int i = 0; i < length; i++)
        printf("%d ", myarray[i]);
    printf("\n");

    array_add(myarray, length); // function call

    printf("Modified array : ");
    for (int i = 0; i < length; i++)
        printf("%d ", myarray[i]);
    printf("\n");

    printf("myarray: %p\n", myarray); // pointer address within main

    return 0;
}

void add(int *x) {

    *x += 1;
}

void array_add(int array[], int size) {
    
    printf("array :  %p\n", array); // pointer address within the function

    for (int i = 0; i < size; i++)
        array[i] += 1;
}