#include <stdio.h>
#include <cuda.h>

__shared__ float partialSum[SIZE];
partialSum[threadIdx.x] = X[blockIdx.x * blockDim.x + threadIdx.x];

unsigned int t = threadIdx.x;
for (unsigned int strid = blockDim.x / 2; stride >= 1; stride = stride>>1) {
    // N.B.: The loop divides the stride by 2 at each iteration.
    __syncthreads();
    i (t < stride) {
        partialSum[t] += partialSum[t + stride];
    }
}