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

    printf("p1  addr  : %p\np2  addr  : %p\n", password1, password2);
    printf("p1 (long) : %ld\np2 (long) : %ld\n",(long) password1, (long) password2);

    printf("\nOutput of each char in the password1 array\n\n");

    printf("\t");
    for (int i = 0; i <= 30; i++)
        printf("%c", password1[i]);
        // printf("%d = %c\n", i, password1[i]); /* this outputs each char in it's array position */
    printf("\n\n---\n\n");

    other_ptr = password1;
    printf("other_ptr copied from p1 : %s\n", other_ptr);

    password1 = realloc(password1, 30 * sizeof(char)); /* this reallocates password1 to a new address, 
                                                          and the other_ptr was assigned to the original 
                                                          address of password1 */ 

    /* When realloc moves the memory and frees the original location, other_ptr is left pointing to memory 
    that no longer belongs to your program (it is a dangling pointer). */                                                        

    printf("\nrealloc of password1\n");
    printf("p1  addr  : %p\np2  addr  : %p\n", password1, password2);
    printf("p1 (long) : %ld\np2 (long) : %ld\n",(long) password1, (long) password2);

    printf("p1 : %s\n\n", password1);
    other_ptr = password1; // required to fix the dangling pointer

    printf("other_ptr addr   : %p\n", other_ptr);
    printf("other_ptr (long) : %ld\n", (long) other_ptr);
    printf("other_ptr string : %s\n", other_ptr); // now outputs correctly ;-)

    printf("\nOutput of each char in the other_ptr array\n\n");

    printf("\t");
    for (int i = 0; i <= 30; i++)
        printf("%c", other_ptr[i]);
        // printf("%d = %c\n", i, other_ptr[i]); /* this outputs each char in it's array position */
    printf("\n\n---\n\n");
    
    free(password1);
    free(password2);
    
    return 0;
}