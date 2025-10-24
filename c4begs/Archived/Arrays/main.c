#include <stdio.h>
#include <stdlib.h>

int main()
{
    char phrase[20] = "Array";
    // int luckyNumbers[] = {4, 8, 15, 16, 23, 42};
    int luckyNumbers[10];
    luckyNumbers[1] = 200;

    printf("%d\n", luckyNumbers[1]);
    printf("%d\n", luckyNumbers[0]);

    printf("%s\n", phrase);

    return 0;
}