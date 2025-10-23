#include <stdio.h>
#include <stdlib.h>

int main()
{
    char color[20], pluralNoun[20], celebrity[50];

    printf("Enter a color : ");
    scanf("%s", color);
    printf("Enter a plural noun : ");
    scanf("%s", pluralNoun);
    
    // Clear the input buffer after scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    /* The loop reads every character left in the buffer one by one 
    until it finds the newline or the end of the input stream. 
    This ensures that the next fgets() call will find an empty buffer 
    and correctly wait for new user input. */

    printf("Enter a celebrity : ");
    fgets(celebrity, 50, stdin);
    // scanf("%s", celebrity); // if the input is "firstname secondname", this won't work

    printf("Roses are %s\n", color);
    printf("%s are blue\n", pluralNoun);
    printf("I love %s\n", celebrity);
    
    return 0;
}