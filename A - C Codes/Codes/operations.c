#include <stdio.h>

int main(int argc, char** argv) {
    int x = 2;
    int y = 3;
    int z = x + y; // Declare z = x + y.
    int v = x++; // Let v = 2, x = 3.
    int w = ++y; // Let y = 4, w = 4.
    return 0;
}