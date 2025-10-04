#include <stdio.h>

typedef struct Book {
    int pages;
    char title[50];
    float price;
} book; // This alias introduces a new type "book" representing Book structures.

int main() {
    book book1 = {354, "Fondamenti di Programmazione", 42.50};

    return 0;
}