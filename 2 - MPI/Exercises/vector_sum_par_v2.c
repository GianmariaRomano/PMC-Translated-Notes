#include <stdio.h>
#include <mpi.h>

// Write a program that, after reading a value from argv, creates two random vectors of size n and parallelly computes their sum.
// N.B.: If p processes are used, make sure that n is a multiple of p, otherwise give a terminal error.

int* create_random_vector(int n) {
    int* v = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 11; // For simplicity, just generate numbers in the range from 0 to 10.
    }
    return v;
}

int main(int argc, char** argv) {
    int p;
    int my_rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int *a, *b;
    int n = atoi(argv[1]); // Convert the input from string to integer.

    // Check whether the workload can be uniformly distributed among processes.
    if (n % p != 0) {
        printf("n must be a multiple of p.\n");
        MPI_Abort(MPI_COMM_WORLD, 1); // Forcibly stop the program and return an error code.
    }

    // Here, process 0 will create the vectors and perform a scatter in place to keep the values in the vector.
    if (my_rank == 0) {
        a = create_random_vector(n);
        b = create_random_vector(n);

        MPI_Scatter(NULL, n / p, MPI_INT, MPI_IN_PLACE, n / p, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Scatter(NULL, n / p, MPI_INT, MPI_IN_PLACE, n / p, MPI_INT, 0, MPI_COMM_WORLD);
    } else {
        a = (int*) malloc(n / p * sizeof(int));
        b = (int*) malloc(n / p * sizeof(int));

        MPI_Scatter(NULL, n / p, MPI_INT, a, n / p, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Scatter(NULL, n / p, MPI_INT, b, n / p, MPI_INT, 0, MPI_COMM_WORLD);
    }

    int* local_c = (int*) malloc(n / p * sizeof(int));
    for (int i = 0; i < n / p; i++) {
        local_c[i] = a[i] + b[i];
    }

    int* c = NULL;
    if (my_rank == 0) {
        c = (int*) malloc(n / p * sizeof(int));
    }

    // Gather the partial sums into c and have process 0 print the full vector.
    MPI_Gather(local_c, n / p, MPI_INT, c, n / p, MPI_INT, 0, MPI_COMM_WORLD);
    if (my_rank == 0) {
        for (int i = 0; i < n; i++) {
            printf("Element %d of c = a + b: %d \n", i, c[i]);
        }
    }

    MPI_Finalize();
    return 0;
}