#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *password;
    char *other_ptr;
    password = malloc(10 * sizeof(char));

    printf("\nTrustworhty Program\n\n");
    printf("Please enter your password : ");
    scanf("%s", password);

    // other_ptr = password;

    other_ptr = malloc((strlen(password) + 1) * sizeof(char));
    strcpy(other_ptr, password);
    printf("\nallocated memory & strcpy 'password' into 'other_ptr'\n");

    printf("\n'password'          : %s\n", password);
    printf("'password' address  : %p\n", password);

    printf("\n'other_ptr'         : %s\n", other_ptr);
    printf("'other_ptr' address : %p\n", other_ptr);

    printf("\n'password' chars array output : ");
    for (int i = 0; i < 10; i++)
        printf("%c", password[i]);
    printf("\n");

    free(password);
    printf("\nfreed 'password' memory\n");

    printf("\n'other_ptr' chars array output : ");
    for (int i = 0; i < 10; i++)
        printf("%c", other_ptr[i]);
    printf("\n");

    printf("\n'password'          : %s\n", password);
    printf("'password' address  : %p\n", password);

    printf("\n'other_ptr'         : %s\n", other_ptr);
    printf("'other_ptr' address : %p\n", other_ptr);

    free(other_ptr);
          
    return 0;
}