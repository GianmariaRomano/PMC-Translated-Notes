#include <stdio.h>
#include <mpi.h> // This library is needed to implement message passing interfaces.

int main(void) {
    MPI_Init(NULL, NULL); // MPI_Init() sets up the program.
    printf("Hello, World!\n");
    MPI_Finalize(); // MPI_Finalize() terminates the program and provides its exit code.
    return 0;
}