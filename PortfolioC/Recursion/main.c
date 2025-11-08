#include <stdio.h>
#include <stdlib.h>

/*  The factorial of n denoted by n!
    is the product of all positive
    integers <= n 
    
    n! = n * (n-1) * (n-2) ... * 1 
    
    5! = 5 * 4 * 3 * 2 * 1 = 120 */

/*  recursion is a way of solving
    a problem where our solution
    depends on solutions to smaller
    instances of the same problem */

/*  practically: functions that call
    themselves! */

int factorial(int n) {

    if (n == 1) return 1;

    return n * factorial(n - 1);
}

int main() {

    int n = 0;
    int fact = 1;
    printf("Enter a number : ");
    scanf("%d", &n);

    // iterative solution
    /* while (n >= 1) {
        fact = n * fact;
        n--;
        printf("n: %d fact: %d\n", n, fact);
    } */

   // recursive solution
   fact = factorial(n); // function call

    printf("fact : %d\n", fact);
    
    return 0;
}