#include <stdio.h>
#include <stdlib.h>

int main() {

    // 2nd version
    int c;
    while((c = getchar()) != EOF) {
        putchar(c);
    }

    /* while (c !=  EOF) {
        putchar(c);
        c = getchar();
    } */
    
    return 0;
}