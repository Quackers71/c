#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Suggested improvements from G-AI mode : https://share.google/aimode/JOItgvRiKhtvVmyYJ

// There is a strlen function provided by string.h
int str_len(char self[]) {

    int i;
    for (i = 0; self[i]; i++);
    return i - 1; // removes the newline character add by fgets
}

int main() {

    char str2rev[101];
    printf("Enter a string : ");
    fgets(str2rev, 100, stdin);

    int total_string_length;

    // retreives the total length of the string
    for (int i = 0; i < str_len(str2rev); i++) {
        total_string_length = i;
    }
 
    printf("In reverse     : ");

    // starts at the last char and reverse prints out each char in the char array 
    for (int x = total_string_length; x >= 0; x--) {
        printf("%c", str2rev[x]);
    }

    printf("\n");
    return 0;
}