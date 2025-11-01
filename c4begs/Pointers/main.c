#include <stdio.h>
#include <stdlib.h>

// https://share.google/aimode/m8VPnkkTkIJ3qnYeW < Key Takeaways from dealiing with Pointers & Memory Addresses

int main() {

    char name[20] = "George";
    char *pName = name; // single pointer to a char array

    int age = 30;
    int * pAge = &age; // created a Pointer variable 

    double gpa = 3.4;
    double * pGpa = &gpa;

    char grade = 'A';
    char * aGrade = &grade;

    printf("name memory address : %p = %s\n", &name, name);
    printf("age memory address : %p = %d\n", &age, age); // &age is a pointer (memory address)
    printf("gpa memory address : %p = %.2f\n", &gpa, gpa);
    printf("grade memory address : %p = %c\n", &grade, grade);
    printf("\n");

    printf("int * pAge = &age;\n");
    printf("double * pGpa = &gpa;\n");
    printf("char * aGrade = &grade;\n");
    printf("char * pName = name;\n");
    printf("\n");

    printf("pName memory address : %p = %s\n", &pName, pName);
    printf("pAge memory address : %p = %d\n", &pAge, *pAge);
    printf("pGpa memory address : %p = %.2f\n", &pGpa, *pGpa);
    printf("aGrade memory address : %p = %c\n", &aGrade, *aGrade);
    
    return 0;
}