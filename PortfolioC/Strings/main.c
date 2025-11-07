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

    char newstring[] = "Working with some Strings!";

    int newlength = strlen(newstring);
    int string_count = 0;
    for (int i = 0; i < newlength; i++)
        if (newstring[i] == 's' || newstring[i] == 'S')
            string_count++;

    printf("New String : %s\n", newstring);
    printf("S Count : %d\n", string_count);

    char s1[] = "My String to copy!";
    char s2[50];

    strcpy(s2, s1);
    printf("s2 copied from s1 = %s\n", s2);

    return 0;
}