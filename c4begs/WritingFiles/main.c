#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE * fpointer = fopen("./employees.txt", "w");
    fprintf(fpointer, "Jim, Salesman\nPam, Receptionist\nOscar, Accounting");
    fclose(fpointer);

    FILE * fpointer_append = fopen("./employees.txt", "a");
    fprintf(fpointer_append, "\nKelly, Customer Service");
    fclose(fpointer_append);

    return 0;
}