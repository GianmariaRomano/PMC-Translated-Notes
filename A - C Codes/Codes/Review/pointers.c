#include <stdio.h>

int main() {
    int *p1, *p2; // Initialize pointers p1 and p2.

    int a = 6;
    int b = 3;

    p1 = &a; // p1 now points at the address where a is stored.
    p2 = &b; // p2 now points at the address where b is stored.

    return 0;
}