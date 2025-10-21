#include <stdio.h>
#include <stdlib.h>

int main()
{
    char line[1000];
    FILE *hand;
    hand = fopen("romeo.txt", "r");
    while( fgets(line, 1000, hand) != NULL ) {
        printf("%s", line);
    }

    printf("\n");
    return 0;
}