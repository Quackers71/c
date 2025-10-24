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
const char *trueOrFalse(int num1, int num2, int num3) {
    int result;
    if (num1 < num2 || num2 > num3) {
        return "True";
    } else {
        return "False";
    }
}

int main() {

    printf("%d\n", max(45, 71, 3));
    printf("%s\n", trueOrFalse(3, 2, 5));

    return 0;
}