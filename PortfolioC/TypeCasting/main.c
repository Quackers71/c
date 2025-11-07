#include <stdio.h>
#include <stdlib.h>

int main() {

    int a = 5;
    int b = 2;

    double c = (double) a / b; // int is promoted

    printf("%d / %d = %d\n", a, b, a / b);
    printf("%d / %d = %.2f\n", a, b, c);

    int x = 2;
    double y = 5;

    double z = x / y; // x here is promoted to a double
    printf("%d / %.2f = %.2f\n",x , y, z);

    int f = 67;
    int g = 6;

    int h = (int) f / g;
    printf("%d / %d = %d\n",f , g, h);
    
    return 0;
}