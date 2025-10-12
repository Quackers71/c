#ifndef ARRAY_H
#define ARRAY_H

// Function prototype for update_file
// Note: In C, an array parameter `int filedata[200]` is treated as a pointer `int *filedata`.
void update_file(int *filedata, int new_filetype, int new_num_lines);

#endif // ARRAY_H
