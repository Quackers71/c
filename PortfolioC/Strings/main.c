#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_chars(char* array_to_print) {
    // length of the string excluding the terminator
    size_t length = strlen(array_to_print);

    for (size_t i = 0; i < length; i++) {
        printf("test[%zu]='%c'\n", i, array_to_print[i]);
    }
    printf("\n");
}

int main() {

    char test[] = "tested";
    printf("test1 : %s\n", test); 
    print_chars(test); // calls the print_chars function

    char test2[] = "Some big long string!";
    printf("test2 : %s\n", test2);
    // print_chars(test2);

    // other use cases of size_t
    char data[] = "C Programming is great!";

    size_t length = strlen(data);
    size_t size_in_bytes = sizeof(data);

    printf("\n%s\n", data);
    printf("String length : %zu characters\n", length);
    printf("Size in bytes : %zu bytes\n", size_in_bytes);

    return 0;
}