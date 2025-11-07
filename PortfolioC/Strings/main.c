#include <stdio.h>
#include <stdlib.h>

int main() {

    char test[] = "tested";
    printf("test1 : %s\n", test);

    int count = sizeof(test) / sizeof(test[0]);

    for (int i = 0; i < count - 1; i++)
        printf("test[%d]='%c'\n", i, test[i]);
    
    char test2[] = "Some big long string!";
    printf("test2 : %s\n", test2);

    return 0;
}