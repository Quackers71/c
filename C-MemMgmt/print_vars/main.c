#include <stdio.h>

int main() {
    int sneklang_default_max_threads = 8;
    char sneklang_default_perms = 'r';
    float sneklang_default_pi = 3.141592;
    char *sneklang_title = "Sneklang";

    // don't touch above this line
    printf("Default max threads : %d\n", sneklang_default_max_threads);
    printf("Default perms : %c\n", sneklang_default_perms);
    printf("Default PI : %f\n", sneklang_default_pi);
    printf("Title : %s\n", sneklang_title);
    return 0;
}