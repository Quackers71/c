#include <stdio.h>
#include <stdlib.h>
#define ROWS 2
#define COLS 3

int main() {

    int a[ROWS][COLS] = { {1,2,3},
                          {4,5,6}};

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
    {
        printf("Enter a[%d][%d] : ", i, j);
        scanf("%d", &a[i][j]);
    }

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
    {
        printf("a[%d][%d]=%d\n",i , j, a[i][j]);
    }

    // printf("a[0][2]=%d\n", a[0][2]);
    // printf("a[1][1]=%d\n", a[1][1]);
    
    return 0;
}