#include <stdio.h>
#include <stdlib.h>

// void memory_hog(int size);

int main() {

    // while (1) memory_hog(128000); // function called to test memory overload

    int size = 10;

    int *a = calloc(size, sizeof(int)); // calloc zero's the heap space first
    // int *a = malloc(sizeof(int) * size); // a dynamically allocated array of 10 integers

    for (int i = 0; i < size; i++)
        a[i] = size - i;

    for (int i = 0; i < size; i++)
        printf("a[%d] = %d\n", i, a[i]);
    printf("\n");

    printf("a:    %p\n", a);

    int *save = a;
    printf("save: %p\n", save);
    for (int i = 0; i < size; i++)
        printf("save[%d] = %d\n", i, save[i]);
    printf("\n");
    
    free(a); // Free the allocated memory block (Heap)

    printf("after free(a)\n");
    printf("save: %p\n", save);
    for (int i = 0; i < size; i++)
        printf("save[%d] = %d\n", i, save[i]);
    printf("\n");

    return 0;
}

/* void memory_hog(int size) {
    int *a = malloc(size);
} */