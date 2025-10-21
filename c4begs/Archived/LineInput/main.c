#include <stdio.h>
#include <stdlib.h>

int main() {
    char line[100];
    printf("Enter line : ");
    fgets(line, 1000, stdin);
    printf("Line : %s\n", line);
}