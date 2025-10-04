#include <stdio.h>
#include <stdlib.h>

// Write a program that lets the suer input as many Cars as they want: each car must contain fields for price and model.
// The program then prints all the input cars.

struct Car {
    float price;
    char model[30];
    struct Car *next; // Declare a pointer to add new elements when needed.
};

struct Car *makeList(); // Declare a function to create a linked list that stores input cars.
void printList(struct Car *p); // Declare a function that, using a pointer, prints the elements in the list.

int main() {
    printf("Start. \n");

    struct Car *p; // Declare the pointer.
    p = makeList(); // Set the pointer to the list.
    printList(p); // Use the pointer to print the list.

    return 0;
}

struct Car *makeList() {
    struct Car *startList = (struct Car *)malloc(sizeof(struct Car));
    if (startList == NULL) {
        printf("It is not possible to create the list. \n");
        return NULL;
    }

    // Start by creating the first element of the list.
    printf("Car 1. \n");
    printf("Model: \n");
    scanf("%s", &startList->model);
    printf("Price: \n");
    scanf("%f", &startList->model);
    printf("\n");
    startList->next = NULL;

    // Now, create a new pointer to slide through the list (the original pointer must be kept as it is to access the list).
    struct Car *ptr;
    ptr = startList;
    
    int go_on = 0, counter = 1;

    // For simplicity, implement an infinite loop that allows users to insert numbers until a break condition.
    while(1) {
        printf("Insert 0 to add a new car: \n");
        scanf("%d", &go_on);
        if (go_on != 0) {
            break;
        }

        ptr->next = (struct Car *)malloc(sizeof(struct Car));
        if (ptr == NULL) {
            printf("It is not possible to allocate any more space.");
            return NULL;
        }

        printf("Car %d \nModel", ++counter);
        printf("%s", &ptr->next->model);
        printf("\nPrice: ");
        scanf("%f", &ptr->next->price);
        ptr = ptr->next;
        ptr->next = NULL; // For the last element, setting next = NULL allows to denote the end of the list.
    }

    return startList;
}

void printList(struct Car *p) {
    printf("Print the cars: \n");
    if (p == NULL) {
        printf("Empty list. \n");
        return;
    } else {
        counter = 1;
        while (p != NULL) {
            printf("Data of car %d", i);
            printf("Car %d - Model: %s, Price: %.2f \n", counter++, p->model, p->price);
            p = p->next; // Move the pointer to the next element, if present.
        }
    }
}