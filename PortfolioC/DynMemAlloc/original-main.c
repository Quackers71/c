#include <stdio.h>
#include <stdlib.h>

// #define SIZE 10

int main() {

    int size = 10;

    int *a = malloc(sizeof(int) * size); // a dynamically allocated array of 10 integers

    for (int i = 0; i < size; i++)
        a[i] = size - i;

    for (int i = 0; i < size; i++)
        printf("a[%d] = %d\n", i, a[i]);
    printf("\n");

    printf("a: %p\n", a);

    free(a); // Free the allocated memory block (Heap)

    return 0;
}