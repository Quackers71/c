#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main() {

    int x, y;
    x = 5;
    y = 10;

    printf("x: %d   y: %d\n", x, y);
    printf("&x : %p\n&y : %p\n", &x, &y);
    swap(&x, &y);

    printf("x: %d  y: %d\n", x, y);
    printf("&x : %p\n&y : %p\n", &x, &y);

    /* int a, b, c;
    a = b = c = 0;

    printf("Enter 3 numbers : ");
    scanf("%d %d %d", &a, &b, &c); // Pass by Reference or Pass by Pointer in C
    printf("Result : %d\n", a + b + c); */
    
    return 0;
}

void swap(int *a, int *b) {

    printf("a  : %p\nb  : %p\n", a, b);
    printf("*a : %d\n*b : %d\n", *a, *b);

    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}