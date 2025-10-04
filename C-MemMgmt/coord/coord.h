#pragma once

// The line #ifndef COORD_H in a C header file is part of a standard technique called an include guard. 
// Its purpose is to prevent the contents of the header file from being included more than once in a
// single compilation unit (a .c file).
// Full explanation can be viewed here : https://share.google/aimode/lUwNMictGEXsmMO7A

#ifndef COORD_H
#define COORD_H

struct Coordinate {
    int x;
    int y;
    int z;
};

// Declare the prototype for the new_coord function
struct Coordinate new_coord(int x, int y, int z);
struct Coordinate scale_coordinate(struct Coordinate c, int scale);

#endif // COORD_H