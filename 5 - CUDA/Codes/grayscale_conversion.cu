#include <stdio.h>
#include <cuda.h>

__global__ void colorToGrayscaleConversion(unsigned char * Pout, unsigned char * Pin, int width, int height) {
    int Col = threadIdx.x + blockIdx.x * blockDim.x;
    int Row = threadIdx.y + blockIdx.y * blockDim.y;

    if (Col < width && Row < height) {
        int grayOffset = Row * width + Col; // Position in the grayscale image.
        int rgbOffset = greyOffset * CHANNELS; // Position in the RGB image.

        unsigned char r = Pin[rgbOffset]; // Red value for the pixel.
        unsigned char g = Pin[rgbOffset + 1]; // Green value for the pixel.
        unsigned char b = Pin[rgbOffset + 2]; // Blue value for the pixel.

        Pout[grayOffset] = 0.21f * r + 0.71f * g + 0.07f * b; // Rescale and store in the grayscale image.
    }
}