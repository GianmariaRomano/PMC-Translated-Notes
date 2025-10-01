#include <stdio.h>
#include <stadlib.h>

union MyData {
    int i;
    char c;
} mydata;

// An int requires 4 bytes of memory space while a char only requires 1 byte.
// MyData therefore requires 4 bytes to contain all its variables.

int main() {
    printf("Allocated memory: %d\n", sizeof(mydata));
    return 0;
}