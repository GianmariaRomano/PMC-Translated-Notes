#include <stdio.h>

// Write a function that, given an array and a value, checks whether the value is found in the array.
// If the value is found, the function returns its position in its array, otherwise it returns error code 404.

int search_value(int*, int, int); // The function takes as inputs: an array, its size and the value to search.

int main() {
    // Try to execute the code on an array of size 10 where arr[i] = i.
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    int v = search_value(arr, 10, 4); // Check if x = 4 is present in the array.
    if (v != 404) {
        printf("The value is at position %d \n", v);
    } else {
        printf("The returned value is: %d \n", v);
    }

    return 0;
}

int search_value(int* arr, int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i; // x is in the array at position i.
        }
    }
    return 404; // x is not in the array.
}