#include <stdio.h>

int main() {
    char buffer[33];
    scanf("%32s", buffer);
    printf("%s\n", buffer);

    return 0;
}