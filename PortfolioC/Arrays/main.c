#include <stdio.h>
#include <stdlib.h>

int main() {

    int grade[] = {91, 82, 73, 64, 55, 46, 37, 28, 19, 10};

    int count = sizeof(grade) / sizeof(grade[0]);
    // printf("There are %d values in the array.\n", count);
    
    for (int i = 0; i < count; i++) {
        printf("grade[%d] = %d\n" , i + 1, grade[i]);
    }

    int total = 0;
    for (int j = 0; j < count; j++)
        total += grade[j];

    int avg = total / count;
    printf("average = %d\n", avg);

    return 0;
}


/*  Original Code

    int grade1 = 91;
    int grade2 = 82;
    int grade3 = 73;

    int total = grade1 + grade2 + grade3;
    int avg = total / 3;
    printf("average : %d\n", avg); */
