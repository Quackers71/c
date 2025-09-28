#include "exercise.h"

char *get_temperature_status(int temp) {
    if (temp < 70) {
        return "too cold";
    } else if (temp > 90) {
        return "to hot";
    } else {
        return "just right";
    }
}