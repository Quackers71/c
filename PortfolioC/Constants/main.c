#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10 // using the define pre-processor statement

void print_array(int *array);

int main() {

    int a[LENGTH] = {0,1,2,3,4,5,6,7,8,9,};
    printf("array length : %d\n", LENGTH);
    print_array(a);

    return 0;
}

void print_array(int *array) {
    for (int i = 0; i < LENGTH; i++)
        printf("array[%d]=%d\n",i , array[i]);
}