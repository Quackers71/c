#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    // User Input

    int age;
    printf("Please enter your age : ");
    scanf("%d", &age);

    printf("You are %d years old\n", age);
    int currentYear = 2024;
    int yearOfBirth = currentYear - age;
    printf("And you were born in %d\n", yearOfBirth);

    double gpa;
    printf("Please enter your gpa : ");
    scanf("%lf", &gpa);

    printf("Your gpa is %.2f\n", gpa);

    char grade;
    printf("Please enter your grade : ");
    scanf(" %c", &grade);

    printf("Your grade is %c\n", grade);

    // NOT THE BEST METHOD :-(
    char forename[25], surname[25];
    printf("Please enter your name : ");
    scanf("%24s %24s", forename, surname);

    // fflush(stdin);
    // fgets( name, sizeof name, stdin);
    // name[strcspn(name, "\n")] = '\0';

    printf("Your name is %s %s\n", forename, surname);

    return 0;

/*
    // Constants

    const int NUM = 5;
    printf("Your constant number is %d\n", NUM);
    // num = 8;
    // printf("%d\n", num);

 
    // printf stuff

    char charName[] = "Russ";
    int charAge = 35;
    int myNum = 7;
    char wordy[] = "number";
    char q = 'q';

    printf("There was a man named %s\n", charName);
    printf("he was %d years old.\n", charAge);
    printf("He really like the name %s\n", charName);
    printf("but did't like being %d.\n", charAge);

    // Data Types
    int age = 40;
    double gpa = 3.6;
    char grade = 'A';
    char phrase[] = "Hello World!";

    double desi = 15.984;
    double a = 5.0;
    double b = 4.5;
    double result = a * b;
    // printf Function
    printf("\"Hello, \nWorld\"\n");

    // format specifier
    printf("My favourite %s is %d\n", wordy, myNum);
    printf("gpa = %f\n", gpa);
    printf("My fave char is %c\n", q);

    // Working with Numbers

    printf("%f\n", desi);
    printf("%.2f * %.2f = %.2f\n", a, b, result);

    // double num;
    // num = 36.356;
    // double ceilResult = ceil(num); 

    printf("2^3 = %.2f\n", pow(2, 3)); // 2^3
    printf("4^3 = %.2f\n", pow(4, 3) ); // 4^3
    printf("Square root of 100 is %.0f\n", sqrt(100) );
    // printf("ceiling of %f is %f\n", num, ceilResult); // don't work in CodeBlocks :-( ?!!!

    printf("ceiling of 36.356 is %.2f\n", ceil(36.356));
    printf("floor of 36.356 is %.2f\n", floor(36.356) );
    */
}
