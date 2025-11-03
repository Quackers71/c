#include <stdio.h>
#include <stdlib.h>

int py_len(char self[]) {
    // char self[]; moved as above
    int i;
    for (i = 0; self[i]; i++);
    return i;
}

int main() {

    char x[] = "Hello";
    // int py_len(); Not required as the definition appears before main
    printf("%s %d\n", x, py_len(x));
    
    return 0;
}