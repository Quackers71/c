#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro for the maximum size of the input buffer
#define BUFFER_SIZE 256

// A helper function for robust double input
double get_double(const char* prompt) {
    char input_buffer[BUFFER_SIZE];
    double number;
    int items_read;

    while (1) {
        printf("%s", prompt);
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
            // Handle error or end-of-life
            printf("Error reading input.\n");
            exit(1);
        }

        // Try to read a double from the buffer 
        items_read = sscanf(input_buffer, "%lf", &number);

        if (items_read == 1) {
        return number; // Successfully read a double, return it
        } else {
        printf("Invalid input, please enter a valid number.\n");
        }
    }
}

int main() {
    char operator;
    double num1, num2;
    char op_buffer[BUFFER_SIZE];

    printf("Please enter your operator (+, -, * or /) : ");
    fgets(op_buffer, sizeof(op_buffer), stdin);
    operator = op_buffer[0]; // Read only the 1st character

    num1 = get_double("Please enter your 1st number : ");
    num2 = get_double("Please enter your 2nd number : ");

    switch (operator) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Error: Invalid operator\n");
            break;
    }

    return 0;
}