#include <stdio.h>
#include <stdbool.h> // To access bools.

// Write a function that, given an array and a value, checks whether the value is found in the array.
// If the value is found, the function returns its (first) position and number of occurrences, otherwise it returns error code 404.

int search_values(int*, int, int, int*); // The function takes as inputs: an array, its size, the value to search and a pointer to a counter.

int main() {
    // Try to execute the code on an array of size 10 where arr[i] = i.
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    int n_occ = 0; // Initialize the counter of occurrences.
    int *ptr_n_occ = &n_occ; // Initialize the pointer to keep track of the occurrences.

    int v = search_values(arr, 10, 4, ptr_n_occ);
    if (v != 404) {
        printf("The value was found for the first time at position %d, appearing for %d time(s) in total \n", v, n_occ);
    } else {
        printf("The returned value is: %d \n", v);
    }

    return 0;
}

int search_values(int* arr, int size, int x, int* occ_ptr) {
    bool find = false;
    int position = 404; // Initialize the position to the error value.
    int n = 0; // Initialize the counter.
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            if (!find) {
                find = true;
                position = i; // The function keeps track of the first time the value appears. If no bool is used, the last time is shown instead.
            }
            n++;
        }
    }

    *occ_ptr = n; // Set the pointer towards the address of the counter.
    return position;
}