#include <stdio.h>
#include <stdlib.h>

int main()
{
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

    // printf Function
    printf("\"Hello, \nWorld\"\n");

    // format specifier
    printf("My favourite %s is %d\n", wordy, myNum);
    printf("gpa = %f\n", gpa);
    printf("My fave char is %c\n", q);

    return 0;
}
