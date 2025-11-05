#include <stdio.h>
#include <stdlib.h>

/* print Fahrenheit - Celsius table
for f = 0, 20, ..., 300 */

int main() {

    int fahr;

    printf("Fahr - Celsius\n");

    for (fahr = 0; fahr <= 300; fahr += 20) {
        printf("%4d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
    
    return 0;
}