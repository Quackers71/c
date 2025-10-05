#include <stdio.h>

void print_numbers(int start, int end) {
    printf("======================\n");
    for (int i = start; i <= end; i++) {
        printf("%d, ", i);
    }
    printf("\b\b \b\n");
    printf("======================\n");
}