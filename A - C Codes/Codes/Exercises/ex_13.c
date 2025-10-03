#include <stdio.h>

// Create a structure "Automobile" that contains fields for price, model, engine size and colour.
// Then, write a program that allows users to insert and print information for three different cars.

struct Automobile {
    float price;
    char model[20];
    int engine_size;
    char colour[20];
}car_1,car_2,car_3; // Define three car structures of type Automobile.

int main() {
    printf("First car: \n");
    printf("Price: \n");
    scanf("%f", &car_1.price);
    printf("\n");
    printf("Model: \n");
    scanf("%s", &car_1.model);
    printf("\n");
    printf("Engine size: \n");
    scanf("%d", &car_1.engine_size);
    printf("Colour: \n");
    scanf("%s", &car_1.colour);

    printf("\n\n");

    printf("Second car: \n");
    printf("Price: \n");
    scanf("%f", &car_2.price);
    printf("\n");
    printf("Model: \n");
    scanf("%s", &car_2.model);
    printf("\n");
    printf("Engine size: \n");
    scanf("%d", &car_2.engine_size);
    printf("Colour: \n");
    scanf("%s", &car_2.colour);

    printf("\n\n");

    printf("Third car: \n");
    printf("Price: \n");
    scanf("%f", &car_3.price);
    printf("\n");
    printf("Model: \n");
    scanf("%s", &car_3.model);
    printf("\n");
    printf("Engine size: \n");
    scanf("%d", &car_3.engine_size);
    printf("Colour: \n");
    scanf("%s", &car_3.colour);

    printf("\n\n");

    printf("Inserted cars: \n");
    printf("First Car - Price: %f, Model: %s, Engine Size: %d, Colour: %s \n", car_1.price, car_1.model, car_1.engine_size, car_1.colour);
    printf("Second Car - Price: %f, Model: %s, Engine Size: %d, Colour: %s \n", car_2.price, car_2.model, car_2.engine_size, car_2.colour);
    printf("Third Car - Price: %f, Model: %s, Engine Size: %d, Colour: %s \n", car_3.price, car_3.model, car_3.engine_size, car_3.colour);

    return 0;
}