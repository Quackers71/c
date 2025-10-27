#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char major[50];
    int number;
    int age;
    double gpa;
};

// Function prototype, takes a pointer to the struct
void printStudent(struct Student *s_ptr) {

    printf("Student : %d\n", s_ptr->number);
    printf("-------\n");
    printf("Name  : %s\n", s_ptr->name);
    printf("Age   : %d\n", s_ptr->age);
    printf("GPA   : %g\n", s_ptr->gpa);
    printf("Major : %s\n", s_ptr->major);
    printf("\n");
};


int main() {    

    struct Student student1;
    student1.number = 1;
    student1.age = 22;
    student1.gpa = 3.2;
    strcpy(student1.name, "Jim");
    strcpy(student1.major, "Business");

    struct Student student2;
    student2.number = 2;
    student2.age = 18;
    student2.gpa = 4.2;
    strcpy(student2.name, "Pam");
    strcpy(student2.major, "Photography");
    
    // Pass the address of the student variable
    printStudent(&student1);
    printStudent(&student2);

    return 0;
};

// again, with a little help from our friendly AI - https://share.google/aimode/ovRkUL7cAqzhtPGOs