#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[30];
    printf("Please enter your name : ");
    fgets(name, 30, stdin);
    // scanf("%s", name);

    int age;
    printf("Please enter your age : ");
    scanf("%d", &age);

    double gpa;
    printf("Please enter your gpa : ");
    scanf("%lf", &gpa);

    char grade;
    printf("Please enter your grade (A-F) : ");
    scanf(" %c", &grade); // because of the previous scanf, you needed a space before %c.

    printf("You name is %s\n", name);
    printf("\033[A"); // because of the fgets input, this moves the cursor up one line.
    printf("you are %d years old\n", age);
    printf("you gpa is %.2f\n", gpa);
    printf("Your grade was a %c\n", grade);

    return 0;
}
