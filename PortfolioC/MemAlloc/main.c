#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int total = 1000;

    int size = 0;
    int *junk = 0;
    srand(time(0));

    for(int i = 0; i < total; i++) {
        size = rand() % 16000;
        junk = malloc(size * sizeof(int));

        for(int j = 0; j < size; j++)
        {
            junk[j] = rand();
        }

        free(junk);
    }

    int *array;
    array = malloc(total * sizeof(int));

    for(int i = 0; i < total; i++)
        printf("%d", array[i]);
    
    free(array);

    printf("\n");
    
    return 0;
}