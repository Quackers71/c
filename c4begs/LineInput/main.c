#include <stdio.h>
#include <stdlib.h>

int main() {
    char line[100];
    printf("Enter line : ");
    scanf("%[^\n]100s", line);
    printf("Line : %s\n", line);
}