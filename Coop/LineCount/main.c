#include <stdio.h>
#include <stdlib.h>

int main() {

    /* count lines in input */
    
    int c, nl = 0;
    
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
    
    return 0;
}