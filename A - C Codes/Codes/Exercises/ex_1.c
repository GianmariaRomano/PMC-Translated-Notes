#include <stdio.h>

// Write a program that reads two input integer numbers and:
// 1) Prints whether the first number is greater than/less than/equal the second number.
// 2) Prints the sum and the prodcut of the numbers.

int main() {
    int a = 0;
    int b = 0;

    printf("Insert the first number: \n");
    scanf("%d", &a);
    printf("Insert the second number: \n");
    scanf("%d", &b);
    printf("\n");

    if (a > b) {
        printf("%d is greater than %d\n", a, b);
    } else if (a < b) {
        printf("%d is less than %d\n", a, b);
    } else {
        printf("%d is equal to %d\n", a, b);
    }

    int s = a + b;
    int p = a * b;
    printf("a + b = %d; a * b = %d\n", s, p);

    return 0;
}