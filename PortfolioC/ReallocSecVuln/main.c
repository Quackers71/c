#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
var:    password1     password2
data:   a b c 1 2 3   x y z 7 8 9
mem:    0 1 2 3 4 5 6 7 8 9 a b c 
*/

int main() {

    char *password1;
    char *password2;

    password1 = malloc(7 * sizeof(char));
    password2 = malloc(7 * sizeof(char));
    strcpy(password1, "abc123");
    strcpy(password2, "xyz789");

    printf("p1 : %p\np2 : %p\n", password1, password2);
    printf("p1 : %d\np2 : %d\n", (int) password1, (int) password2);

    printf("\n");

    free(password1);
    free(password2);
    
    return 0;
}