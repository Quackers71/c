#include <stdio.h>
#include <stdlib.h>

int main() {

    int b = 42;
    int *a = &b;

    printf(" b: %d\n", b);
    printf("&b: %p\n", &b);
    printf(" a: %p\n", a);

    *a = 50;

    printf(" b: %d\n", b);
    printf("&b: %p\n", &b);
    printf(" a: %p\n", a);
    
    return 0;
}