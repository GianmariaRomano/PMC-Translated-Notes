#include <stdio.h>

int main(int argc, char** argv) {
    int x;
    printf("Enter an integer value for x: ");
    scanf("%d", &x);

    if (x % 2 == 0) {
        printf("x^2 = %d\n", x * x);
    } else {
        printf("x + 3 = %d\n", x + 3);
    }

    return 0;
}