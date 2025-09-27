#include <stdio.h>

// Write a program that reads an input number and prints all numbers from 0 to a in ascending and descending order.
// Use a while loop.

int main() {
    int n = 0;

    printf("Insert a number: \n");
    scanf("%d", &n);
    printf("\n");

    int i = 0;

    printf("Ascending loop: \n");
    while (i <= n) {
        printf("%d  ", i);
        i++;
    }

    printf("\n");

    i = n;

    printf("Descending loop \n");
    while (i >= 0) {
        printf("%d  ", i);
        i--;
    }

    return 0;
}