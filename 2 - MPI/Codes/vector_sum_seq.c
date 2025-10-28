#include <stdio.h>

void vector_sum(double x[], double y[], double z[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        z[i] = x[i] + y[i];
    }
}