#ifndef COORDINATE_H
#define COORDINATE_H

typedef struct Coordinate {
    int x;
    int y;
    int z;
} coordinate_t;

// Declare the prototype for the new_coordinate function
coordinate_t new_coordinate(int x, int y, int z);

// Declare the prototype for the coordinate_update_x function
void coordinate_update_x(coordinate_t coord, int new_x);

// Declare the prototype for the coordinate_update_and_return_x function
coordinate_t coordinate_update_and_return_x(coordinate_t coord, int new_x);

#endif // COORDINATE_H
