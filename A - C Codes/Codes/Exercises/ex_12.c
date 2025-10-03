#include <stdio.h>
#include <stdlib.h>

// Write a program that that reads input integer numbers and dynamically stores them in an array until a zero is inserted.
// The program then prints the minimum and maximum values of the array.

int main() {
    int *array; // Declare a pointer for the array.
    int counter = 0; // Initialize a counter of inserted numbers.

    // For simplicity, implement an infinite loop that allows users to insert numbers until a break condition.
    while(1) {
        printf("Insert an integer number (choose 0 to continue): \n");
        int a = 0;
        scanf("%d", &a);
        if (a == 0) {
            if (counter == 0) {
                printf("No element was inserted. \n"); // There are no elements to check and the program ends.
                return 0;
            }
            break;
        }
        array = = realloc(array, (counter + 1) * (sizeof(int))); // Resize the memory space needed for the array.
        if (array == NULL) {
            printf("It is not possible to allocate memory. \n");
            exit(1);
        }
        counter++;
        array[counter - 1] = a;
        printf("\n");
    }

    int i = 0;
    int min_v = array[0]; // Initialize the minimum to a default value.
    int max_v = array[0]; // Initialize the maximum to a default value.

    for (i = 0; i < counter; i++) {
        if (array[i] < min_v) {
            min_v = array[i];
        }

        if (array[i] > max_v) {
            max_v = array[i];
        }
    }

    printf("Minimum value: %d \n", min_v);
    printf("Maximum value: %d \n", max_v);

    // Remember to free the allocated memory for future programs.
    free(array);
    printf("Program ended: free up the memory space. \n");

    return 0;
}