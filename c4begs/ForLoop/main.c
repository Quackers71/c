#include <stdio.h>
#include <stdlib.h>

int main() {

    int luckNumbers[] = {4, 8, 15, 16, 23, 42};
    int i;
    for(i = 0; i  < 6 ; i++) {
        printf(" array position %d value is %d\n",i , luckNumbers[i]);
    }

    return 0;
}