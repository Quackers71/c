#include <stdio.h> // Need this for printf

typedef struct Codefile {
    int lines;
    int filetype;
} codefile_t;

// Declare the prototype for the helper function to print codefile_t info
void print_codefile_info(const char *label, codefile_t cf);

// Declare the prototype for the change_filetype function
codefile_t change_filetype(codefile_t *f, int new_filetype);
