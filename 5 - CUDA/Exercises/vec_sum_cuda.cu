#include <stdio.h>
#include <cuda.h>

// Start by taking the host memory locations of the vectors.
// Then, define the GPU memory allocations for computations.
// When done, copy the output from the GPU to the host.
void vec_sum(float* h_A, float* h_B, float* h_C, int n) {
    int size = n * sizeof(float); // Define the memory needed for storing each vector.
    float *d_A, *d_B, *d_C; // Define pointers for allocating the vectors on the GPU memory.

    // Start by allocating the input vectors on the GPU memory.
    cudaMalloc((void **) &d_A, size);
    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMalloc((void **) &d_B, size);
    cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    // Then, allocate memory on the output vector and, after performing computations, copy the result on the host memory.
    cudaMalloc((void **), &d_C, size);
    vec_sum_kernel<<<ceil(n/256.0), 256>>>(d_A, d_B, d_C, n); // Use n threads and place 256 threads per block.
    cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

    // Lastly, free the allocated GPU memory.
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
}

// Write the function that will perform computations on the GPU.
__global__ void vec_sum_kernel(float* A, float* B, float* C, int n) {
    int i = blockDim.x * blockIdx.x + threadIdx.x; // Get the global position of the thread.
    if (i < n) {
        C[i] = A[i] + B[i]; // Remember that the program may use more threads than the number of elements.
    }
}
