#include <stdio.h>

// Write a program that allows the user to fill two arrays of size 5.
// Then, declare pointers that swap the first element of the first array with the last element of the second array and so on.
// The program then prints the modified arrays.

int main() {
    int arr_1[5], arr_2[5];
    int i = 0;

    for (i = 0; i < 5; i++) {
        printf("Input element %d for the first array: \n", i);
        scanf("%d", &arr_1[i]);
        printf("Input element %d for the second array: \n", i);
        scanf("%d", &arr_2[i]);
    }

    int *p1, *p2;
    p1 = &arr_1[0]; // Set the first pointer towards the first element of the first array.
    p2 = &arr_2[4]; // Set the second pointer towards the last element of the second array.

    for (i = 0; i < 5; i++) {
        int x = *p1; // x contains the value stored in the address indicated by p1.
        *p1 = *p2; // p1 now stores the value indicated by p2.
        *p2 = x; // p2 now stores x, which is the value previously indicated by p1.

        p1++; // Point at the next element.
        p2--; // Point at the previous element as it started from the last element.
    }
    
    printf("Printing the modified arrays.\n");
    
    for (i = 0; i < 5; i++) {
        printf("arr_1[%d]: %d \n", i, arr_1[i]);
        printf("arr_2[%d]: %d \n", i, arr_2[i]);
    }

    return 0;
}