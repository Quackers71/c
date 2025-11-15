#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    clock_t tic, toc;
    int *array;

    tic = clock();
    array = malloc(1000000 * sizeof(int));
    toc = clock();
    printf("malloc: %fs\n", (double) (toc - tic) / CLOCKS_PER_SEC);
    free(array);

    tic = clock();
    array = calloc(1000000, sizeof(int)); // calloc comes with a performance cost
    toc = clock();
    printf("calloc: %fs\n", (double) (toc - tic) / CLOCKS_PER_SEC);
    free(array);


    /* int total = 1000;

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
    array = calloc(total, sizeof(int)); // with calloc, zero's the heap space

    for(int i = 0; i < total; i++)
        printf("%d", array[i]);
    
    free(array);

    printf("\n"); */
    
    return 0;
}