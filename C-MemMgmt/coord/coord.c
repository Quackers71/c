// #pragma once
#include "coord.h"

// designated initializer's

coordinate_t new_coord(int x, int y, int z) {
    coordinate_t coord = {
        .x = x, 
        .y = y, 
        .z = z
    };
    return coord;
};

coordinate_t scale_coordinate(coordinate_t coord, int factor) {
    coordinate_t scaled = {
        .x = coord.x * factor,
        .y = coord.y * factor,
        .z = coord.z * factor,
    };
    return scaled;
}