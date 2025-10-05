#include <stdio.h>

int get_integer(void) {
    return 42;
}

/* void print_integer(int x) {
    printf("the value : %d\n", x);
} */

int main() {
    // print_integer();
    printf("void : %d\n", get_integer());
}