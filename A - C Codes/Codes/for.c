#include <stdio.h>

int main() {
    int sum = 0;

    for (int i = 0; i <= 10; i++) {
        sum += i;
    }

    printf("Sum of integers from 0 to 10: %d\n", sum);
    return 0;
}