#include <stdio.h>
#include <stdlib.h>

void func1(int *ptr);

int main() {
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        printf("It is not possible to allocate space! \n");
        return 0;
    }

    *p = 30;
    printf("p = %d \n", *p); // Print 30.

    func1(p); // Modify the variable indicated by p.

    printf("p = %d \n", *p); // Print 13.

    return 0;
}

void func1(int *ptr) {
    *ptr = 13;
}