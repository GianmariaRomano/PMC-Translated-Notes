#include <stdio.h>

// Write a program that reads an input number and prints all numbers from 0 to a in ascending and descending order.
// Use a for loop.

int main() {
    int n = 0;

    printf("Insert a number: \n");
    scanf("%d", &n);
    printf("\n");

    int i = 0;

    printf("Ascending loop: \n");
    for (i = 0; i <= n; i++) {
        printf("%d  ", i);
    }

    printf("\n");

    printf("Descending loop \n");
    for (i = n; i >= 0; i--) {
        printf("%d  ", i);
    }

    return 0;
}