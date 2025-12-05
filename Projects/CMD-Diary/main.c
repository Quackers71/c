#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256
#define TIMESTAMP_LENGTH 100
#define FILENAME "journal.log"

void get_timestamp(char* buffer, size_t buffer_size);
int append_diary(const char* user_input, const char* filename);
int get_next_id(const char* filename);

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

        // sscanf used to extract the option, Expect a single character
        if (sscanf(op_buffer, "%c", &option) == 1) {
            // to check if the character is one of the valid options
            if (option == 'l' || option == 'a' || option == 'd' || option == 'q') {
                valid_option = 1; // Input is valid, so exit the loop
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

            char user_input[BUFFER_SIZE];

            // get User input
            printf("Add your entry : ");
            // fget reads your input, including spaces
            if (fgets(user_input, BUFFER_SIZE, stdin) == NULL) {
                fprintf(stderr, "Error reading input.\n");
                return EXIT_FAILURE;
            }

            // remove trailing newline char if present
            size_t input_len = strlen(user_input);
            if (input_len > 0 && user_input[input_len - 1] == '\n') {
                user_input[input_len - 1] = '\0';
            }

            // call function to handle file operation
            if (append_diary(user_input, FILENAME) == EXIT_SUCCESS) {
                printf("Entry successfully added to %s.\n", FILENAME);
            } else {
                // error message already printed by append_diary
                return EXIT_FAILURE;
            }

            break;
        case 'd':
            printf("you chose to delete an entry\n");
            break;
        case 'q':
            printf("you chose to quit the application\n");
            return 1; // Exit the program, immediately
            break;
        default:
            printf("Error: Invalid operator\n");
            break;
    }
    
    printf("The End\n");
    return 0;
}

void get_timestamp(char* buffer, size_t buffer_size) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime); // get the current time
    timeinfo = localtime(&rawtime); // convert to local time structure

    // format the time as "YYYY-MM-DD HH:MM:SS"
    strftime(buffer, buffer_size, "%Y-%m-%d %H:%M:%S", timeinfo);
}

int append_diary(const char* user_input, const char* filename) {
    printf("appending\n");
    FILE *fp;
    char timestamp[TIMESTAMP_LENGTH]; 
    int entry_id;

    get_timestamp(timestamp, TIMESTAMP_LENGTH);
    entry_id = get_next_id(filename); // get the ID b4 opening in append mode

    // open file in append mode 'a'
    fp = fopen(filename, "a");
    if (fp == NULL) {
        fprintf(stderr, "Error opening the file %s in append mode.\n", filename);
        return EXIT_FAILURE; // return failure status
    }

    // write the timestamp & user input into the file
    fprintf(fp, "[%d] [%s] %s\n", entry_id, timestamp, user_input);

    fclose(fp);

    printf("Entry successfully added to %s\n", FILENAME);

    return EXIT_SUCCESS;
}

int get_next_id(const char* filename) {
    FILE *fp;
    int count = 0;
    int c;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        // if the file doesn't exist, the first ID will be 1
        return 1;
    }
    // count lines by couting newline chars
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    fclose(fp);
    // count of newlines
    return count + 1;
}