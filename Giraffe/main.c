#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int max(int num1, int num2, int num3) {
    int result;
    if(num1 >= num2 && num1 >= num3){
        result = num1;
    } else if(num2 >= num1 && num2 >= num3) {
        result = num2;
    } else {
        result = num3;
    }
    return result;

}

int main() {

    // If Statements

    printf("%d\n", max(80, 30, 70));

    if (!(3 < 2 || 2 > 5)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}


/*

double cube(double num) {
    double result = num * num * num;
    return result;
    // return num * num * num; would do the same thing!
    printf("Print this..."); // The return result; will break out of the function
}

int main() {

    // Return Statements

    printf("Answer : %.2f\n", cube(7.0));

    return 0;
}



void sayHi() {
    printf("Hello User\n");
}

void sayHiName(char name[], int age) {
    int currentYear = 2024;
    int yob = currentYear - age;
    printf("Hi %s, you were born in %d\n", name, yob);
}

int main()
{
    // Functions

    printf("Top\n");
    sayHi();
    printf("Bottom\n\n");
    sayHiName("Bob", 53);
    sayHiName("Tom", 32);
    sayHiName("Val", 70);
    sayHiName("Reg", 8);

    return 0;
}


    // Arrays

    int luckyNumbers[] = {4, 8, 15, 16, 23, 42};
    int size = sizeof(luckyNumbers)/sizeof(luckyNumbers[0]);
    for (int i = 0; i < size; i++) {
      printf("%d\n", luckyNumbers[i]);
    }
    printf("The first number is %d\n", luckyNumbers[0]);

    luckyNumbers[0] = 200;
    printf("The first number is now %d\n", luckyNumbers[0]);

    int unLuckyNumbers[10];
    unLuckyNumbers[1] = 80;
    printf("The first unlucky number is %d\n", unLuckyNumbers[1]);

    char phrase[20] = "Arrays Yo!";
    printf("%s\n", phrase);


    // Mad Libs

    char color[20];
    char pluralNoun[20];
    char celebrity[20];

    printf("Please enter a color : ");
    scanf("%s", color);
    printf("Please enter a plural noun : ");
    scanf("%s", pluralNoun);
    printf("Please enter a celebrity : ");
    scanf("%s", celebrity);

    printf("Roses are %s\n", color);
    printf("%s are blue\n", pluralNoun);
    printf("I love %s\n",celebrity);


    // Basic Calculator

    double num1;
    double num2;

    printf("Please enter your first number :");
    scanf("%lf", &num1);
    printf("Please enter your second number :");
    scanf("%lf", &num2);

    printf("%.2f + %.2f = %.2f\n",num1, num2, num1 + num2);

    
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
