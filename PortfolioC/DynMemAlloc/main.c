#include <stdio.h>
#include <stdlib.h>

// void memory_hog(int size);

int main() {

    // while (1) memory_hog(128000); // function called to test memory overload

    int size = 0;
    printf("Enter size : ");
    scanf("%d", &size);

    int *a = calloc(size, sizeof(int)); // calloc zero's the heap space first
    // int *a = malloc(sizeof(int) * size); // a dynamically allocated array of 10 integers

    for (int i = 0; i < size; i++)
        a[i] = size - i;
    printf("a: %p\n", a);

    for (int i = 0; i < size; i++)
        printf("a[%d] = %d\n", i, a[i]);
    printf("\n");

    printf("a: %p\n", a);

    a = realloc(a, sizeof(int) * (size + size)); // re-allocating memory

    for (int i = size; i < (size+size); i++) a[i] = 9;

    for (int i = 0; i < (size+size); i++)
        printf("a[%d] = %d\n", i, a[i]);
    printf("\n");
    
    free(a); // Free the allocated memory block (Heap)

    return 0;
}

/* void memory_hog(int size) {
    int *a = malloc(size);
} */