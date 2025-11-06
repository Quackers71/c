#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
int add(int a, int b);
int mult(int x, int y);
void print_int(int a); // none returning func

int main() {

    // printf("Hello World!\n");

    int output = add(6, 7);
    printf("Output : %d\n", output);

    int multoutput = mult(9, 9);
    printf("Mult Output : %d\n", multoutput);

    print_int(5);
    
    return 0;
}

int add(int a, int b) {
    int result = a + b;
    return result;
}

int mult(int x, int y) {
    int result = 0;
    for (int i = 0; i < x;  i++)
        result = add(result, y);
    return result;
}

void print_int(int a) {
    printf("INT : %d\n", a);
}