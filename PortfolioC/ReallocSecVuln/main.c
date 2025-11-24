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
    char *other_ptr;

    password1 = malloc(7 * sizeof(char));
    password2 = malloc(7 * sizeof(char));
    strcpy(password1, "abc123");
    strcpy(password2, "xyz789");

    printf("p1 addr  : %p\np2 addr  : %p\n", password1, password2);
    printf("p1 (int) : %ld\np2 (int) : %ld\n",(long) password1, (long) password2);

    printf("\n");

    for (int i = 0; i < 100; i++)
        printf("%c", password1[i]);
    printf("\n\n");

    other_ptr = password1;
    printf("other ptr copied from p1 : %s\n\n", other_ptr);

    password1 = realloc(password1, 20 * sizeof(char));

    printf("p1 addr  : %p\np2 addr  : %p\n", password1, password2);
    printf("p1 (int) : %ld\np2 (int) : %ld\n",(long) password1, (long) password2);

    printf("p1 : %s\n\n", password1);

    printf("other ptr addr : %ld\n", (long) other_ptr);

    printf("other ptr str  : %s\n", other_ptr); // supposed to print copy of password1 but doesn't?!!

    for (int i = 0; i < 100; i++)
        printf("%c", other_ptr[i]);
    printf("\n\n");
    
    free(password1);
    free(password2);
    
    return 0;
}