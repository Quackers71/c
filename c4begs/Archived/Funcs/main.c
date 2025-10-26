#include <stdio.h>
#include <stdlib.h>

void sayHi(char name[], int age) {
    printf("Hello %s, you are %d years old\n", name, age);
}

int main() {
    
    sayHi("John", 50);
    sayHi("Tarquin", 21);
    sayHi("Kylie", 57);

    return 0;
}
