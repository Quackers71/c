#include <stdio.h>
#include <stdlib.h>

int main() {

    char *password;
    char *other_ptr;
    password = malloc(10 * sizeof(char));

    printf("\nTrustworhty Program\n\n");
    printf("Please enter your password : ");
    scanf("%s", password);

    other_ptr = password;
    printf("password  : %s\n", password);
    printf("other_ptr : %s\n", other_ptr);

    free(password);
    printf("\nfree(password) executed\n");

    printf("password  : %s\n", password);
    printf("other_ptr : %s\n", other_ptr);

    // in the demo this printed out the string of chars entered by the User
    printf("other_ptr chars : ");
    for (int i = 0; i < 10; i++)
        printf("%c", other_ptr[i]);
    printf("\n");
            
    return 0;
}