#pragma once
#include "coord.h"

// designated initializer's

struct Coordinate new_coord(int x, int y, int z) {
    struct Coordinate c = {
        .x = x,
        .y = y,
        .z = z,
    };
    return c;
};