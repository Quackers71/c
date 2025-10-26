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

// https://share.google/aimode/d2LsDrq0DbeH4uYL9 < This explains what I missed when creating this function
/* It also provides another method to return an integer to represent boolean logic, where 1 is true and 0 is false.
   This avoids complex memory management and is safer */ 

const int trueOrFalse(int num1, int num2, int num3) {
    if (num1 < num2 || num2 > num3) {
        return 1;
    } else {
        return 0;
    }
}

/* const char *trueOrFalse(int num1, int num2, int num3) {
    int result;
    if (num1 < num2 || num2 > num3) {
        return "True";
    } else {
        return "False";
    }
} */

int main() {

    printf("%d\n", max(45, 71, 3));

    // Ternary operator is used to print the string based on the integer result
    printf("%s\n", trueOrFalse(3, 2, 5) ? "True" : "False");

    return 0;
}