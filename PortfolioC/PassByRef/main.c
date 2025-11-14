#include <stdio.h>
#include <stdlib.h>

// In C technically this is really Pass by Pointer

void swap(int a, int b);
void swap2(int *a, int *b);

int main() {

    int x = 5;
    int y = 10;

    printf("x: %d\ny: %d\n", x, y);

    swap2(&x, &y);
    printf("swap x & y\n");

    printf("x: %d\ny: %d\n", x, y);
    
    return 0;
}

void swap(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b) {
    int temp;
    temp = *a; // de-referencing
    *a = *b;
    *b = temp;
}