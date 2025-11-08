#include <stdio.h>
#include <stdlib.h>

// #define LENGTH 10 // using the define pre-processor statement

void print_array(int *array, int size);

const int len = 5; // This is a compile time constant and can be used in any function including main

int main() {

    int a[] = {0,1,2,3,4,5,6,7,8,9,};
    print_array(a, 10);

    printf("\n");
    int b[] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
    print_array(b, 12);

    printf("len: %d\n", len);

    return 0;
}

void print_array(int *array, int size) {
    const int length = size; // Constant variable, only exists (scope) within the function
    for (int i = 0; i < length; i++)
        printf("array[%d]=%d\n",i , array[i]);

    printf("len: %d\n", len);
}