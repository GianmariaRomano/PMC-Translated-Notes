#include <stdio.h>
#include <stdlib.h>

// Write a program that creates a list with 20 elements, each containing a field for value.
// The value of each element is set equal to its position in the list.
// The program then creates the following functions:
// 1) struct Element *makeList(), which creates the list.
// 2) struct Element *elimFirst(struct Element *p), which eliminates the first element.
// 3) void elimTenth(struct Element *p), which eliminates the tenth element.
// 4) void elimTwentieth(struct Element *p), which eliminates the twentieth element.
// 5) void printList(struct Element *p), which prints the list.
// The program uses these functions to eliminate the first, tenth and last elements of the list and, upon eliminating an item, prints the modified list.

typedef struct Element {
    int value;
    struct Element *next;
};

// Start by declaring the functions to implement.
struct Element *makeList(); // Create the list and return the pointer to the first element.
struct Element *elimFirst(struct Element *p); // Eliminate the first element of the list by pointing to the next element.
void elimTenth(struct Element *p); // Eliminate the tenth element of the list by pointing to the following element.
void elimTwentieth(struct Element *p); // Eliminate the last element of the list by moving the NULL pointer before it.
void printList(struct Element *p); // Print the list using a pointer.

int main() {
    struct Element *p = makeList();

    // Start by printing the lists.
    printf("Original list. \n");
    printList(p);
    printf("\n");

    p = elimFirst();
    printf("First modified list. \n");
    printList(p);
    printf("\n");

    elimTenth(p);
    printf("Second modified list. \n");
    printList(p);
    printf("\n");

    elimTwentieth(p);
    printf("Third modified list. \n");
    printList(p);
    printf("\n");

    return 0;
}

struct Element *makeList() {
    struct Element *ptr, *ptr2;
    ptr = (struct Element *)malloc(sizeof(struct Element));
    if (ptr == NULL) {
        printf("It is not possible to create the list.");
        return NULL
    }

    ptr->value = 1;
    ptr2 = ptr;

    int i = 0;
    for (i = 1; i < 20; i++) {
        ptr2->next = (struct Element *)malloc(sizeof(struct Element));
        if (ptr2 == NULL) {
            printf("It is not possible to add any other value to the list.");
            return NULL
        }

        ptr2 = ptr2->next;
        ptr2->valore = i + 1;
        ptr2->next = NULL; // For the last element, setting next = NULL allows to denote the end of the list.
    }

    return ptr;
}

struct Element *elimFirst(struct Element *p) {
    if (p == NULL) {
        printf("Empty list. \n");
        return NULL;
    }
    p = p->next;
    return p
}

void elimTenth(struct Element *p) {
    if (p == NULL) {
        printf("Empty list. \n");
        return NULL;
    }

    while (p->next->valore != 10) {
        p = p->next;
    }

    p->next = p->next->next; // Skip the tenth element and point to the following one.
}

void elimTwentieth(struct Element *p) {
    if (p == NULL) {
        printf("Empty list. \n");
        return NULL;
    }

    while (p->next->next != NULL) {
        p = p->next;
    }

    p->next = NULL; // End the list at the second-to-last element.
}

void printList(struct Element *p) {
    while (p != NULL) {
        printf("--> %d", p->valore);
        p = p->next;
    }
}