#include <stdio.h>
#include <stdlib.h>

int main() {
    int usf, euf;
    printf("Enter US Floor  : ");
    scanf("%d", &usf);
    euf = usf - 1;
    printf("The EU Floor is : %d\n", euf);
}