#include <stadio.h>
#include <stdlib.h>

// Write a program the defines the following functions:
// 1) char *readString(), which reads an input string and allocates it in the memory.
// 2) void replaceDigits(char *p), which replaces each digit in the string with '*'.
// The program first reads and prints the input string and then, after modifying the string, it prints the output.
// Use dynamic memory allocation.

char *readString();
void replaceDigits(char *p);

int main() {
    char *string = readString; // Create the pointer to the string.
    if (string == NULL) {
        printf("It is not possible to allocate memory. \n");
        return 1;
    }

    printf("Input string: %s \n", string);
    replaceDigits(string);
    printf("Output string: %s \n", string);

    return 0;
}

char *readString() {
    char c, *string;
    string = malloc(sizeof(char)); // Try to allocate memory to store the string.
    if (string == NULL) {
        return string;
    }

    scanf("%c", &c);
    int i;
    for (i = 0; c != '\n'; i++) {
        string[i] = c;
        if (!(string = realloc(string, (i + 2) * sizeof(char)))) {
            printf("Error in memory allocation. \n");
            return string;
        }
        scanf("%c", &c);
    }

    string[i] = '\0'; // Add the terminating character to mark the end of the string.

    return string;
}

void replaceDigits(char *p) {
    int i = 0;
    while (p[i] != '\0') {
        if ((p[i] >= '0') && (p[i] <= '9')) {
            p[i] = '*';
        }
        i++;
    }
    return;
}