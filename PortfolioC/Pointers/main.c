#include <stdio.h>
#include <stdlib.h>

int main() {

    int a, b, c;
    a = b = c = 0;

    printf("Enter 3 numbers : ");
    scanf("%d %d %d", &a, &b, &c); // Pass by Reference or Pass by Pointer in C
    printf("Result : %d\n", a + b + c);
    
    return 0;
}
