#include <stdio.h>
#include <cuda.h>

int deviceCount = 0;
cudaGetDeviceCount(&deviceCount);

if (deviceCount == 0) {
    printf("No CUDA compatible for the GPU exists! \n");
} else {
    cudaDeviceProp pr;
    for (int i = 0; i < deviceCount; i++) {
        cudaGetDeviceProperties(&pr, i); // Get the properties of device i.
        printf("Device #%d is %s \n", i, pr.name);
    }
}