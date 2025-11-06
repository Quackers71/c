#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0

int main() {

    /* count lines, words, chars in input */
    
    int chars, numline, numword, numchar, inword;

    inword = NO;
    numline = numword = numchar = 0;
    while ((chars = getchar()) != EOF) {
        ++numchar;
        if (chars == '\n')
            ++numline;
        if (chars == ' ' || chars == '\n' || chars == '\t')
            inword = NO;
        else if ( inword == NO ) {
            inword = YES;
            ++numword;
        }
    }

    printf("%d line(s), %d word(s) %d character(s) including spaces\n", numline, numword, numchar -1);

    // CTRL + D to exit

    return 0;
}