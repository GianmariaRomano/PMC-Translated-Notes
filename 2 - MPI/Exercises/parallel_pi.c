#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

// Start by extracting the numbers at random through the rand() function.
double get_rand_minus_one_one() {
    return 2 * (rand() / (double)RAND_MAX) - 1;
}

int main(int argc, char** argv) {
    // Start by taking the number of tosses from the specified terminal input.
    // N.B.: On paper, one should make sure that an input is effectively specified in argv.
    int num_tosses = atoi(argv[1]); // Convert the input from string to integer.
    int i;
    int local_hit = 0, total_hit = 0;

    int comm_sz;
    int my_rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    srand(time(NULL) ^ (my_rank * 0x9e3779b9)); // Get the current time as a seed for pseudorandom number generation.

    int local_tosses = num_tosses / comm_sz; // Assume for simplicity that num_tosses is a multiple of comm_sz.

    for (i = 0; i < local_tosses; i++) {
        double x = get_rand_minus_one_one();
        double y = get_rand_minus_one_one();
        if (x*x + y*y <= 1) {
            local_hit++;
        }
    }
    
    // Perform a reduction to collect the local results and compute the total result.
    MPI_Reduce(&local_hit, &total_hit, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Here, process 0 will print the estimate.
    if (my_rank == 0) {
        double pi_estimate = 4 * (total_hit / (double)(num_tosses));
        printf("Estimate of pi: %f\n", pi_estimate);
    }

    MPI_Finalize();
    return 0;
}
