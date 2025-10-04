#include <stdio.h>

int main() {
    int x;

    printf("Enter an integer value for x: ");
    scanf("%d", &x);

    switch (x) {
        case 0:
            printf("0\n");
            break;
        case 100:
            printf("1\n");
            break;
        default:
            printf("?\n");
            break;
    }

    return 0;
}
