#include <stdio.h>
#include <stdlib.h>

// Passing an array to a Function

void add(int *x);
void array_add(int array[]);

int main() {

    int a = 5;
    add(&a);
    printf("a: %d\n", a);

    int myarray[5] = {1,2,3,4,5};
    for (int i = 0; i <=sizeof(myarray[i]); i++)
        printf("%d ", myarray[i]);
    printf("\n");

    array_add(myarray);

    for (int i = 0; i <= sizeof(myarray[i]); i++)
        printf("%d ", myarray[i]);
    printf("\n");

    printf("myarray: %p\n", myarray);

    return 0;
}

void add(int *x) {
    *x += 1;
}

void array_add(int array[]) {
    printf("array: %p\n", array);
    array[0] += 1;
}