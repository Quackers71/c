#pragma once

void coordinate_update_x (coordinate_t coord, int new x) {
    coord.x = new_x;
};
coordinate_t coordinate_update_and_return(coordinate_t coord, int new_x) {
    coord.x = new_x;
    return coord;
}