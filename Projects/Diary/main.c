#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define BUFFER_SIZE 256
#define TIMESTAMP_LENGTH 100
#define FILENAME "journal.log"
#define TEMP_FILENAME "temp_journal.log" // temporary filename

void get_timestamp(char* buffer, size_t buffer_size);
int append_diary(const char* user_input, const char* filename);
int get_next_id(const char* filename);
int handle_add_entry(const char* filename); // new function prototype
int output_list(const char* filename);
int delete_entry(const char* filename);
int get_id_from_line(const char* line); // new function to parse ID from log line

int main() {

    char option;
    char op_buffer[BUFFER_SIZE];
    int valid_option;

    do {
        valid_option = 0; // reset flag for each new prompt cycle
        while (!valid_option) {
            printf("(l) list entries | (a) add an entry | (d) delete an entry | (q) to quit\n");
            printf("Please choose an option : ");
            if (fgets(op_buffer, sizeof(op_buffer), stdin) == NULL) {
                printf("Error reading the input.\n");
                // depending on error handling, exit or continue
                continue;
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
        switch (option) {
            case 'l':
                if (output_list(FILENAME) != EXIT_SUCCESS) {
                    fprintf(stderr, "Failed to output the list\n");
                }
                break;
            case 'a':
                if (handle_add_entry(FILENAME) != EXIT_SUCCESS) {
                    fprintf(stderr, "Failed to add entry.\n");
                }
                break;
            case 'd':
                if (output_list(FILENAME) != EXIT_SUCCESS) {
                    fprintf(stderr, "Failed to output the list\n");
                    break;
                }
                if (delete_entry(FILENAME) != EXIT_SUCCESS) {
                    fprintf(stderr, "Failed to delete the entry\n");
                }
                break;
            case 'q':
                printf("you chose to quit the application\n");
                return 0; // Exit the program, immediately
                break;
            default:
                printf("Error: Invalid operator\n");
                break;
        }
    } while (1);

    return 0; // to exit the program
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

    printf("You successfully added '%s' to the %s\n", user_input, FILENAME);
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

int handle_add_entry(const char* filename) {
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
    if (append_diary(user_input, filename) == EXIT_SUCCESS) {
        return EXIT_SUCCESS;
    } else {
        // error message already printed by append_diary
        return EXIT_FAILURE;
    }
}

int output_list(const char* filename) {
    FILE *fp;
    // ensure buffer is large enough for ID + Timestamp + Entry
    char line_buffer[BUFFER_SIZE + TIMESTAMP_LENGTH + 20];
    fp = fopen(filename, "r");
    if (fp == NULL) {
        // if the file doesn't exist, there will be no entries to output
        printf("The Journal file '%s' doesn't exist, or is empty.\n", filename);
        return EXIT_FAILURE;
    }

    printf("\n--- Journal Entries ---\n");
    while (fgets(line_buffer, sizeof(line_buffer), fp) != NULL) {
        printf("%s", line_buffer);
    }
    printf("--- End of Entries ---\n");

    fclose(fp);
    return EXIT_SUCCESS;
}

int delete_entry(const char* filename) {
    FILE *fp_in, *fp_out;
    int id_to_delete;
    char user_input_buffer[BUFFER_SIZE];
    char line_buffer[BUFFER_SIZE + TIMESTAMP_LENGTH + 20];
    int entry_deleted = 0;
    int input_success = 0;

    while (!input_success) {
        printf("Please Enter an ID to delete, or (q) to cancel : ");
        if (fgets(user_input_buffer, BUFFER_SIZE, stdin) == NULL) {
            printf("Error reading the input.\n");
            return EXIT_FAILURE;
        }

        user_input_buffer[strcspn(user_input_buffer, "\n")] = '\0';
        if (strcmp(user_input_buffer, "q") == 0) {
            printf("Deletion Cancelled.\n'n");
            return EXIT_SUCCESS; // User cancelled out of deletion function
        }
        // sscanf used to extract the option, Expect a single character
        if (sscanf(user_input_buffer, "%d", &id_to_delete) == 1 && id_to_delete > 0) {
            input_success = 1; // valid ID

        } else {
            printf("Error: Invalid input, please enter a positive ID or 'q'.\n");
        }
    }
    // 2. open files for processing
    fp_in = fopen(filename, "r");
    if (fp_in == NULL) {
        printf("Error: Cannot open Journal file '%s'.\n", TEMP_FILENAME);
        return EXIT_FAILURE;
    }
    fp_out = fopen(TEMP_FILENAME, "w");
    if (fp_out == NULL) {
        fprintf(stderr, "Error opening temp file '%s'.\n", TEMP_FILENAME);
        fclose(fp_in);
        return EXIT_FAILURE;
    }
    // 3. read input file by line & write non-matching ID's to temp file
    while (fgets(line_buffer, sizeof(line_buffer), fp_in) != NULL) {
        int current_id = get_id_from_line(line_buffer);
        if (current_id == id_to_delete) {
            entry_deleted = 1;
            printf("-> Deleting entry [ID %d]\n", id_to_delete);
            // skip writing this line to the temp file
        } else {
            fprintf(fp_out, "%s", line_buffer);
            // write all other lines to the temp file
        }
    }
    // 4. close files
    fclose(fp_in);
    fclose(fp_out);

    // 5. replace original file with temp file
    if (entry_deleted) {
        if (remove(filename) != 0) {
            fprintf(stderr, "Error removing the original file.\n");
            remove(TEMP_FILENAME); // clean up the temp file
            return EXIT_FAILURE;
        }
        if (rename(TEMP_FILENAME, filename) != 0) {
            fprintf(stderr, "Error renaming temp file to original filename.\n");
            return EXIT_FAILURE;
        }
        printf("Entry [ID %d] was successfully deleted.\n\n", id_to_delete);
    } else {
        // ID wasn't found, delete the temp file
        printf("Error: Entry [ID %d] not found in the Journal.\n\n", id_to_delete);
        remove(TEMP_FILENAME); // again, clean up the temp file
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int get_id_from_line(const char* line) {
    int id = 0;
    // check the line starts with '['
    if (line[0] == '[' && isdigit((unsigned char)line[1])) {
        // sscanf to extract integer between the []
        sscanf(line, "[%d]", &id);
    }

    return id;
}