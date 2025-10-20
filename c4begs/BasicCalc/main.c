#include <stdio.h>
#include <stdlib.h>

int main()
{
    char operator;
    double num1, num2;

    printf("Please enter your operator (+, -, * or /) : ");
    scanf("%c", &operator);

    printf("Enter your first number : ");
    scanf("%lf", &num1);

    printf("Enter your second number : ");
    scanf("%lf", &num2);

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
            if (num1 && num2 != 0) {
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
