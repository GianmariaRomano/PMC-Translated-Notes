#include <stdio.h>

int main() {
    int sum = 0;
    int i = 0;

    do {
        sum += i;
        i++;
    } while (i <= 10);

    printf("Sum of integers from 0 to 10: %d\n", sum);
    return 0;
}