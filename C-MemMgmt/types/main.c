#include <stdio.h>

int main() {
    int max_recursive_calls = 100;
    char io_mode = 'w';
    float throttle_speed = 0.2;

    // don't touch this line below
    // %d, %c, %f are format specifers
    printf("Max recursive calls : %d\n", max_recursive_calls);
    printf("IO mode : %c\n", io_mode);
    printf("Throttle speed : %.2f\n", throttle_speed);
    return 0;
}