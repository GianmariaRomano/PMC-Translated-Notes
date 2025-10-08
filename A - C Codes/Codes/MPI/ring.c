#include <mpi.h>
#include <stdio.h>

int main(void) {
    int numtasks, rank, next, prev, buf[2];
    MPI_Request reqs[4]; // Required variable for non-blocking calls.
    MPI_Status stats[4]; // Required variable for Waitall routine.

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Find the ranks to determine the left and right neighbors.
 
    prev = (rank - 1+ numtasks) % numtasks; // To avoid negative ranks for process 0.
    next = (rank + 1) % numtasks;

    // Post non-blocking receives and sends for the neighbors.
    MPI_Irecv(&buf[0], 1, MPI_INT, prev, 0, MPI_COMM_WORLD, &reqs[0]);
    MPI_Irecv(&buf[1], 1, MPI_INT, next, 0, MPI_COMM_WORLD, &reqs[1]);
    MPI_Isend(&rank, 1, MPI_INT, prev, 0, MPI_COMM_WORLD, &reqs[2]);
    MPI_Isend(&rank, 1, MPI_INT, next, 0, MPI_COMM_WORLD, &reqs[3]);

    // Wait for all non-blocking send/receive operations to complete before exiting.
    MPI_Waitall(4, reqs, stats);

    MPI_Finalize();
    return 0;
}