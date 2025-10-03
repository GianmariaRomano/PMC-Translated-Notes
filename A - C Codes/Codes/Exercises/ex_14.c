#include <stdio.h>

// Create a structure "Book" that contains fields for title and price.
// Write a function that takes as input two books and returns 0 if they have the same values in both fields or 1 otherwise.

typedef struct Book{
    char title[50];
    float price;
}Book; // Use typedef to simplify future declarations.

int checkBooks(Book b1, Book b2);

int main() {
    Book b1, b2;

    printf("First book: \n");
    printf("Title: \n");
    scanf("%s", &b1.title);
    printf("\n");
    print("Price: \n");
    scanf("%f", &b1.price);
    printf("\n");

    printf("Second book: \n");
    printf("Title: \n");
    scanf("%s", &b2.title);
    printf("\n");
    print("Price: \n");
    scanf("%f", &b2.price);
    printf("\n");

    if (checkBooks(b1, b2) == 0) {
        printf("The two books are equal!");
    } else {
        printf("The two books are different!");
    }

    return 0;
}

int checkBooks(Book b1, Book b2) {
    if ((strcmp(b1.title, b2.title) == 0) && (b1.price == b2.price)) {
        return 0;
    } else {
        return 1;
    }
}