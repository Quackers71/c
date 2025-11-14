#include <stdio.h>
#include <stdlib.h>

// runtime memory allocation

int main() {

    int *a;
    int length = 0;

    printf("Enter a length : ");
    scanf("%d", &length);

    a = malloc(length * sizeof(int));

    printf("a: %p\n", (void*)a); // cast pointer to void*

    for (int i = 0; i < length; i++)
        a[i] = i;

    for (int i = 0; i < length; i++)
        printf("a[%d]=%d\n", i, a[i]);

    size_t total_bytes = length * sizeof(int);   
    printf("sizeof array : %zu\n", total_bytes); // use %zu with size_t, handles large amounts of memory

    free(a);
    
    return 0;
}
