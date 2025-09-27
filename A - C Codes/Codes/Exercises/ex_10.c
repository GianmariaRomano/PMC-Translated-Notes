#include <stdio.h>

// Write a function that, given a vector A of size n and a vector B of size m, returns 1 if A is included in B or 0 otherwise.
// A vector A is said to be included in another vector B if all its elements appear in B as well.
// For instance, A = {2, 1, 3, 2, 1} is included in B = {5, 1, 3, 2}, but not in C = {5, 3, 2, 0}.

int is_included(int A[], int n, int B[], int m) {
    for (int i = 0; i < n; i++) {
        int j = 0;
        while ((j < m) && (B[j] != A[i])) {
            j++;
        }
        if (j == m) {
                return 0;
            }
    }
    return 1;
}

int main() {
    // Try to execute the code with the following vectors.
    int A[5] = {2, 1, 3, 2, 1};
    int B[4] = {5, 1, 3, 2};
    // int B[4] = {5, 3, 2, 0}; // Example where A is not included in B.

    int check = is_included(A, 5, B, 4);
    if (check == 1) {
        printf("Vector A is included in vector B \n");
    } else {
        printf("Vector A is not included in vector B \n");
    }

    return 0;
}