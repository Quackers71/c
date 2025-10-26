#include <stdio.h>
#include <stdlib.h>

double cube(double num) {
    return num * num * num; // this breaks you out of the function
    
    /* double result = num * num * num;
    return result; */
}

int main() {

    printf("Answer : %.2f\n", cube(7.0));

    return 0;
}