#include <stdio.h>

// Write a program that stores an input string into a char array of size 10.
// The program then replaces every digit with * and prints the modified string.
// Use a char pointer in this case.

int main() {
    char arr[10];
    char *c;
    c = &arr[0];

    printf("Insert a string: \n");
    scanf("%s", arr);

    while (*c != '\0') {
        if ((*c >= '0') && (*c <= '9')) {
            *c = '*';
        }
        c++;
    }

    printf("%s \n", arr);

    return 0;
}