#include <stdio.h>
#include <stdlib.h>

// Write a program that that reads input integer numbers and dynamically stores them in an array until a zero is inserted.
// The program then prints the sum of all integers.

int main() {
    int *array; // Declare a pointer for the array.
    int counter = 0; // Initialize a counter of inserted numbers.

    // For simplicity, implement an infinite loop that allows users to insert numbers until a break condition.
    while(1) {
        printf("Insert an integer number (choose 0 to continue): \n");
        int a = 0;
        scanf("%d", &a);
        if (a == 0) {
            break;
        }
        array = realloc(array, (counter + 1) * (sizeof(int))); // Resize the memory space needed for the array.
        if (array == NULL) {
            exit(1);
        }
        counter++;
        array[counter - 1] = a; // Place the value in its position.
        print("\n");
    }

    int i = 0;
    int total = 0;

    for (i = 0; i < counter; i++) {
        total += array[i];
    }

    printf("The sum of the array is: %d", total);

    // Remember to free the allocated memory for future programs.
    free(array);
    printf("Program ended: free up the memory space. \n");

    return 0;
}