#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2, int num3) {
    int result;
    if (num1 >= num2 && num1 >= num3) {
        result = num1;
    } else if (num2 >= num1 && num2 >= num3) {
        result = num2;
    } else {
        result = num3;
    }
    return result;
}

// https://share.google/aimode/ugLWISCDtqmVjaRia < This explains what I missed when creating this function
/* It also provides another method to return an integer to represent boolean logic, where 1 is true and 0 is false.
   This avoids complex memory management and is safer */ 

const char *trueOrFalse(int num1, int num2, int num3) {
    return (num1 < num2 || num2 > num3)? "True" : "False";
}

int main() {

    printf("%d\n", max(45, 71, 3));

    // Ternary operator is used to print the string based on the integer result
    // This has been changed back for now!
    printf("%s\n", trueOrFalse(3, 2, 5));

    return 0;
}