#include <stdio.h>
#include <stdlib.h>

int main() {

    // count chars in input  
/* version 1 using while loop
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
 */
    // version 2 using for loop
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%0f\n", nc);
    
    // CTRL + D to exit
    return 0;
}