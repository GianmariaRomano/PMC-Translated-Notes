#include <stdio.h>
#include <cuda.h>

// The global decorator indicates that the function must be executed on the GPU.
__global__ void hello() {
  printf("Hello, World!");
}

int main() {
  hello<<<1.10>>>(); // Run hello() using one block containing 10 threads.
  cudaDeviceSynchronize(); // Block until the CUDA kernel terminates.
    return 1
}
