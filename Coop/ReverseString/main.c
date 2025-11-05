#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Suggested improvements from G-AI mode : https://share.google/aimode/JOItgvRiKhtvVmyYJ

int main() {

    char str2rev[101];
    printf("Enter a string : ");
    fgets(str2rev, 100, stdin);

    int total_string_length;

    // retrieves the total length of the string using the strlen function provided by string.h
    for (int i = 0; i < strlen(str2rev); i++) {
        total_string_length = i;
    }
 
    printf("In reverse     : ");

    // starts at the last char and reverse prints out each char in the char array 
    for (int x = total_string_length - 1; x >= 0; x--) {
        printf("%c", str2rev[x]);
    }

    printf("\n");
    return 0;
}