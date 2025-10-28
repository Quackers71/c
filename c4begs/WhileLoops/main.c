#include <stdio.h>
#include <stdlib.h>

int main() {

    int index = 1;
    while(index <= 5) {
        printf("%d\n", index);
        index += 1;
    }

    index = 6;
    do {
        printf("%d\n", index);
        index ++;
    } while (index <= 10);

    return 0;
}