#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char major[50];
    int age;
    double gpa;
};

int main() {
    
    struct Student student1;
    student1.age = 22;
    student1.gpa = 3.2;
    strcpy( student1.name, "Jim");
    strcpy( student1.major, "Business");
    
    printf("%s\n", student1.name);
    printf("%d\n", student1.age);
    printf("%f\n", student1.gpa);
    printf("%s\n", student1.major);

    struct Student student2;
    student2.age = 18;
    student2.gpa = 4.2;
    strcpy( student2.name, "Pam");
    strcpy( student2.major, "Photography");
    
    printf("%s\n", student2.name);
    printf("%d\n", student2.age);
    printf("%f\n", student2.gpa);
    printf("%s\n", student1.major);

    return 0;
};
