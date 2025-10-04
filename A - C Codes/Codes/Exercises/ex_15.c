#include <stdio.h>

// Write a program that creates a structure "Person" that contains fields for name, surname, age and birthdate.
// In particular, birthdate is also a structure containing fields for day, month and year.
// The program then creates an array of size 5 to save input instances of type Person and prints the contents of the array.

typedef struct Date {
    int day;
    int month;
    int year;
}date; // Use typedef for simplicity inside the Person structure.

typedef struct Person {
    char name[20];
    char surname[20];
    int age;
    date birthdate;
}person; // Use typedef to simplify declaration.

int main() {
    person people[5];
    int i = 0;

    for (i = 0; i < 5; i++) {
        printf("Person %d: \n", i + 1);
        printf("Name: \n");
        scanf("%s", &people[i].name);
        printf("\n");
        printf("Surname: \n");
        scanf("%s", &people[i].surname);
        printf("\n");
        printf("Age: \n");
        scanf("%d", &people[i].age);
        printf("\n");
        printf("Birthdate (use the dd/mm/yy format): \n");
        scanf("%d/%d/%d", &people[i].birthdate.day, &people[i].birthdate.month, &people[i].birthdate.year);
        printf("\n");
    }

    printf("List of people: \n");
    for(i = 0; i < 5; i++){
        printf("Data of person %d: \n", i + 1);
        printf("Name: %s \n", people[i].name);
        printf("Surname: %s \n", people[i].surname);
        printf("Age: %d years old \n", people[i].age);
        printf("Date of Birth: %d/%d/%d", people[i].birthdate.day, people[i].birthdate.month, people[i].birthdate.year);
        printf("\n");
    }

    return 0;
}