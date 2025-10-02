#include <stdio.h>
#include "exercise.h"
#include "exercise.c"

void test(int start, int end) {
    printf("Printing from %d to %d:\n", start, end);
    print_numbers_reverse(start, end);
    // printf("======================\n");
}

int main() {
    test(10, 1);
}