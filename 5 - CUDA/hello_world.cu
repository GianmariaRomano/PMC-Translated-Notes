#include <stdio.h>
#include <cuda.h>

__global__ void hello() {
  printf("Hello, World!");
}

int main() {
  hello<<<1.10>>>();
  cudaDeviceSynchronize(); // Block until the CUDA kernel terminates.
    return 1
}
