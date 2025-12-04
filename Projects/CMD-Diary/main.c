#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 256

int main() {

    char option;
    char op_buffer[BUFFER_SIZE];
    int valid_option = 0; // Flag to control the loop

    while (!valid_option) {
        printf("(l) list entries | (a) add an entry | (d) delete an entry | (q) to quit\n");
        printf("Please choose an option : ");
        if (fgets(op_buffer, sizeof(op_buffer), stdin) == NULL) {
            printf("Error reading the input.\n");
        }

        if (sscanf(op_buffer, "%c", &option) == 1) {
            if (option == 'l' || option == 'a' || option == 'd' || option == 'q') {
                valid_option = 1;
            } else {
                printf("Error: Invalid option, please try again!\n");
            }
        } else {
            printf("Error: Invalid input format, please enter a single character.\n");
        }
    }

    switch (option)
    {
        case 'l':
            printf("you chose to list entries\n");
            break;
        case 'a':
            printf("you chose to add an entry\n");
            break;
        case 'd':
            printf("you chose to delete an entry\n");
            break;
        case 'q':
            printf("you chose to quit the application\n");
            return 1;
            break;
        default:
            printf("Error: Invalid operator\n");
            break;
    }
    
    printf("The End\n");
    return 0;
}