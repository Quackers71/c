typedef struct Codefile {
    int lines;
    int filetype;
} codefile_t;

// Declare the prototype for the coordinate_update_and_return_x function
codefile_t change_filetype(codefile_t *f, int new_filetype);
