#include <stdio.h>

void print_numbers_reverse(int start, int end) {
    printf("======================\n");
    int i = start;
    while (i >= end) {
        printf("%d, ", i);
        i--;
    }
    printf("\b\b \b\n");
    printf("======================\n");
}