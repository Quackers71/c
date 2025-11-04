#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Suggested improvements from G-AI mode : https://share.google/aimode/JOItgvRiKhtvVmyYJ

int str_len(char self[]) {

    int i;
    for (i = 0; self[i]; i++);
    return i - 1;
}

int main() {

    char str2rev[101];
    printf("Enter a string : ");
    fgets(str2rev, 100, stdin);

    // printf("You entered    : %s", str2rev); //, str_len(str2rev));

    // char last_char_value;
    int total_string_length;

    for (int i = 0; i < str_len(str2rev); i++) {
        // printf("%d : %c\n", i, str2rev[i]);

        // last_char_value = str2rev[i];
        total_string_length = i;
    }

    // printf("\nThe last char is '%c'\n", last_char_value);
    
    // int last_value = last_char_value;
    // printf("%d\n", total_string_length);
 
    printf("In reverse     : ");

    for (int x = total_string_length; x >= 0; x--) {
        printf("%c", str2rev[x]);
    }

    printf("\n");
    return 0;
}