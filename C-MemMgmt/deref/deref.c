#include "deref.h"

codefile_t change_filetype(codefile_t *f, int new_filetype) {
    codefile_t new_f = *f; // This is the dereferencing happening
    new_f.filetype = new_filetype;
    return new_f;
}
