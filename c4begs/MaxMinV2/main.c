#include <stdio.h>
#include <stdlib.h>

int main()
{
    int first = 1;
    int val, maxval, minval;

    printf("Enter 3 numbers e.g. 1 9 5 then press Enter\n");
    
    printf("and then CTRL+D to finish\n");

    while (scanf("%d", &val) != EOF) {
        if ( first || val > maxval ) maxval = val;
        if ( first || val < minval ) minval = val;
        first = 0;
    }
    
    printf("Maximum %d\n", maxval);
    printf("Minimum %d\n", minval);
    
    return 0;
}