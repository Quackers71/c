#include <stdio.h>
#include <stdlib.h>

// Realloc Basics

int main() {

    // int orig_total = 5;
    // int new_total = 10;

    /* int *a = malloc(sizeof(int) * orig_total);

    for(int i = 0; i < orig_total; i++) // [0] > [4]
        a[i] = i;

    for(int i = 0; i < orig_total; i++) //  output range 0 > 4
        printf("a[%d] = %d\n", i, a[i]); 

    printf("a before : %p\n", a);
    a = realloc(a, sizeof(int) * new_total); // gives you more space on the heap
    printf("a after  : %p\n", a);

    for(int i = orig_total; i < new_total; i++) // [5] > [9]
        a[i] = i;

    for(int i = 0; i < new_total; i++) //  output range 0 > 9
        printf("a[%d] = %d\n", i, a[i]);

    free(a);

    printf("\n"); */

    int *a1 = malloc(sizeof(int) * 5); 
    int *a2 = malloc(sizeof(int) * 5);

    for(int i = 0; i < 5; i++) a1[i] = i;
    for(int i = 0; i < 5; i++) a2[i] = 9;

    printf("a1 : %p\n", a1);
    printf("a2 : %p\n", a2);

    printf("a1 : range 0 to 4\n");
    for(int i = 0; i < 5; i++) //  output range 0 to 4 of a1
        printf("a1[%d] = %d\n", i, a1[i]);

    printf("a2 : range 0 to 4\n");
    for(int i = 0; i < 5; i++) //  output range 0 to 4 of a2
        printf("a2[%d] = %d\n", i, a2[i]);

    printf("a1 : range 0 to 14\n");
    for(int i = 0; i < 15; i++) //  output range 0 to 14 of a1
        printf("a1[%d] = %d\n", i, a1[i]);

    printf("a1 b4 realloc: %p\n", a1);
    
    int *save = a1; // saving the original memory address
    printf("save = a1\n");
     printf("save b4 : %p\n", save);
    printf("save range 0 to 4\n");
    for(int i = 0; i < 5; i++) //  output range 0 to 4 of save
        printf("save[%d] = %d\n", i, save[i]);

    a1 = realloc(a1, sizeof(int) * 20);
    printf("a1 reallocated memory\n");
    printf("a1   aft : %p\n", a1);
    printf("save aft : %p\n", save);

    for(int i = 5; i < 20; i++) a1[i] = i;

    printf("a1 after realloc - range 0 to 4\n");
    for(int i = 0; i < 5; i++) //  output range 0 to 4 of a1
        printf("a1[%d] = %d\n", i, a1[i]);

    printf("save after realloc - range 0 to 4\n");
    for(int i = 0; i < 5; i++) //  output range 0 > 4 of save
        printf("save[%d] = %d\n", i, save[i]);

    free(a1);
    free(a2);
    
    return 0;
}