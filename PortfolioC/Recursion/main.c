#include <stdio.h>
#include <stdlib.h>

int main() {

    int n = 0;
    int fact = 1;
    printf("Enter a number : ");
    scanf("%d", &n);

    while (n >= 1) {
        fact = n * fact;
        n--;
        printf("n: %d fact: %d\n", n, fact);
    }

    printf("fact : %d\n", fact);
    
    return 0;
}