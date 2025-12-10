#include <stdio.h>
#include <cuda.h>

__global__ void stencil_1d(int *in, int *out) {
    __shared__ int temp[BLOCK_SIZE + 2 * RADIUS]; // RADIUS adds a padding on both sides.
    int gindex = threadIdx.x + blockIdx.x * blockDim.x; // Global index in the grid.
    int lindex = threadIdx.x + radius; // Local index in the shared memory.

    // Read input elements into the shared memory.
    temp[lindex] = in[gindex];
    if (threadIdx.x < RADIUS) {
        temp[lindex - RADIUS] = in[gindex - RADIUS];
        temp[lindex + BLOCK_SIZE] = in[gindex + BLOCK_SIZE];
    }

    __syncthreads(); // Synchronize all threads within a block to avoid dependencies.

    // Apply the stencil to perform computations.
    int result = 0;
    for (int offset = -RADIUS; offset <= RADIUS; offset++) {
        result += temp[lindex + offset];
    }

    // Store the result.
    out[gindex] = result;
}