#include <stdio.h>

struct Article {
    int articleID;
    float price;
}; // The semicolon is used because this is a declaration.

int main() {
    struct Article a1 = {467, 12.5}; // Direct initialization.

    struct Article a2; // Simple declaration.
    a2.articleID = 189; // Assignment by access.
    a2.price = 34.99;

    printf("a1 - Code: %d, Price: %0.2f \n", a1.articleID, a1.price);
    printf("a2 - Code: %d, Price: %0.2f \n", a2.articleID, a2.price);

    return 0;
}