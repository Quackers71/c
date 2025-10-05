#include <stdio.h>

int main() {
    int sneklang_int_size = 64;
    sneklang_int_size = 32;
    const int x = 5;

    printf("Sneklang int size : %d bits\n", sneklang_int_size);
    printf("your const x : %d\n", x);
    return 0;
}