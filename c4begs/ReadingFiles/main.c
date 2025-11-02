#include <stdio.h>
#include <stdlib.h>

int main() {

    char line[255];
    FILE * fpointer = fopen("./employees.txt","r"); 
    
    while(fgets(line, 255, fpointer) != NULL) {
        printf("%s", line);
    };

    printf("\n");

    return 0;
}