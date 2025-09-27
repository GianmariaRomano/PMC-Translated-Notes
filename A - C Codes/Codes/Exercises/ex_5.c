#include <stdio.h>

// Write a program that stores a string in a char array of size 20.
// The program then replaces every digits with * and prints the modified string.

int main() {
    char arr[20];

    printf("Insert a string: \n");
    scanf("%s", arr);

    int i = 0;

    while (arr[i] != '\0') {
        if ((arr[i] >= '0') && (arr[i] <= '9')) {
            arr[i] = '*';
        }
        i++;
    }

    printf("%s \n", arr);

    return 0;
}