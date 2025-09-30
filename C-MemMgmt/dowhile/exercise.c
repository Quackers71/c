#include <stdio.h>

void print_numbers_reverse(int start, int end) {
    printf("======================\n");
    int i = start;
    do {
        printf("%d, ", start);
        start--;
    } while (start >= end);

    printf("\b\b \b\n");
    printf("======================\n");
}