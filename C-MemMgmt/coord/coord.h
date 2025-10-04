#pragma once

// The line #ifndef COORD_H in a C header file is part of a standard technique called an include guard. 
// Its purpose is to prevent the contents of the header file from being included more than once in a
// single compilation unit (a .c file).
// Full explanation can be viewed here : https://share.google/aimode/lUwNMictGEXsmMO7A

#ifndef COORD_H
#define COORD_H

typedef struct Coordinate {
    int x;
    int y;
    int z;
} coordinate_t;

// Declare the prototype for the new_coord function
coordinate_t new_coord(int x, int y, int z);
coordinate_t scale_coordinate(coordinate_t c, int scale);

#endif // COORD_H