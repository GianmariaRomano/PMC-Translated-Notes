#include <stdio.h>

int main() {
    int sum = 0;
    int i = 0;

    while (i <= 10) {
        sum += i;
        i++;
    }

    printf("Sum of integers from 0 to 10: %d\n", sum);
    return 0;
}