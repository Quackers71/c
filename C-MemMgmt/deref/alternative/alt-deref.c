#include <stdio.h>
#include "alt-deref.h"

// Implementation of the helper function
void print_codefile_info(const char *label, codefile_t cf) {
    printf("\n%s.lines    = %d > %p\n", label, cf.lines, (void *)&cf.lines);
    printf("%s.filetype = %d   > %p\n", label, cf.filetype, (void *)&cf.filetype);
}

codefile_t change_filetype(codefile_t *f, int new_filetype) {
    codefile_t new_f = *f;
    new_f.filetype = new_filetype;
    return new_f;
}
