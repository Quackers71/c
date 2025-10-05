#include <stdio.h>

int main() {
    int x = 5;
    printf("int x = 5\n");
    printf("x is %d            @ %p\n", x, &x);

    int y = x;
    printf("int y = x\n");
    printf("y is %d            @ %p\n", y, &y);

    x = 7;
    printf("x = 7\n");
    printf("x is %d            @ %p\n", x, &x);

    int *x_ptr = &x;
    printf("int *x_ptr = &x\n");
    printf("*x_ptr is %d       @ %p\n", *x_ptr, &x_ptr);

    int z = *x_ptr;
    printf("int z = *z_ptr\n");
    printf("z is %d            @ %p\n", z, &z);

    *x_ptr = 12;
    printf("*x_ptr = 12\n");
    printf("*x_ptr is %d      @ %p\n", *x_ptr, &x_ptr);
    printf("x is now %d       @ %p\n", x, &x);
}