#include <stdio.h>
#include <stdlib.h>

int mymult(int a, int b) 
    // int a, b; declare in the function
{
    int c = a * b;
    return c;
}

int main() {
    // int mymult(); not require as retval calls the function declaration
    int retval;

    retval = mymult(6, 7);
    printf("Answer : %d\n", retval);    
    
    return 0;
}