#include <stdio.h>

// Write a program that stores five input numbers in an array and:
// 1) Prints the minimum and maximum values.
// 2) Prints the sum of the numbers.
// Use a for loop.

int main() {
    int arr[5];
    int i = 0;

    for (i = 0; i < 5; i++) {
        printf("Insert value %d: \n", i);
        scanf("%d", &arr[i]);
    }

    int min_v = arr[0]; // Initialize the minimum to a placeholder value.
    int max_v = arr[0]; // Initialize the maximum to a placeholder value.
    int sum_v = 0; // Initialize the sum to 0.

    for (i = 0; i < 5; i++) {
        if (arr[i] < min_v) {
            min_v = arr[i];
        }

        if (arr[i] > max_v) {
            max_v = arr[i];
        }

        sum_v += arr[i];
    }

    printf("Minimum value: %d\n", min_v);
    printf("Maximum value: %d\n", max_v);
    printf("Sum of the values: %d\n", sum_v);

    return 0;
}