#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// BTW There was a little (bit more than a little) help from our AI Buddies in the Cloud
// https://share.google/aimode/5CnE3bcBCTP3RA8BM

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
    double num1, num2, result;
    char op_buffer[BUFFER_SIZE];
    int valid_operator = 0; // Flag to control the loop

    num1 = get_double("Please enter your 1st number : ");

    while (!valid_operator) {
        printf("Please enter your operator (+, -, * or /) : ");
        if (fgets(op_buffer, sizeof(op_buffer), stdin) == NULL) {
            printf("Error reading the input.\n");
            exit(1);
        }

        // Use sscanf to extract the operator. Expect a single character.
        if (sscanf(op_buffer, "%c", &operator) == 1) {
            // Check if the character is one of the valid operators
            if (operator == '+' || operator == '-' || operator == '*' || operator == '/' ) {
                valid_operator = 1; // Input is valid, exit the loop
            } else {
                printf("Error: Invalid operator, please try again.\n");
            }
        } else {
            printf("Error: Invalid input format, please enter a single character.\n");
        }
    }
    
    num2 = get_double("Please enter your 2nd number : ");

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                // If num2 is not zero (e.g. 25), perform the division.
                result = num1 / num2;
            } else {
                // If num2 is zero, print the error.
                printf("Error: Division by zero is not allowed.\n");
                return 1; // Exit the program immediately
            }
            break;
        default:
            printf("Error: Invalid operator\n");
            break;
    }
    
    // Using %g for all floating-point output automatically handles the formatting
    // for both whole and fractional numbers.
    printf("%g %c %g = %g\n", num1, operator, num2, result);

    return 0;
}