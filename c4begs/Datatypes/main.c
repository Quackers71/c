#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age = 40;
    double gpa = 3.6;
    float score = age / gpa;
    char grade = 'A';
    char name[] = "George";

    printf("Name: %s\n", name);
    printf("Age : %d\n", age);
    printf("gpa : %.2f\n", gpa);
    printf("%s scored an %c grade\n", name, grade);
    printf("%s's age divided by his gpa = %.2f\n", name, score);

    return 0;
}