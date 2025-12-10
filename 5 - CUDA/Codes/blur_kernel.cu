#include <stdio.h>
#include <cuda.h>

__global__ void blurKernel(unsigned char * in, unsigned char * out, int w, int h) {
    int Col = threadIdx.x + blockIdx.x * blockDim.x;
    int Row = threadIdx.y + blockIdx.y * blockDim.y;

    if (Col < w && Row < h) {
        int pixVal = 0;
        int pixels = 0;

        // Get the average value of the pixel's surrounding box.
        for (int blurRow = -BLUR_SIZE; blurRow < BLUR_SIZE + 1; ++blurRow) {
            for (int blurCol = -BLUR_SIZE; blurCol < BLUR_SIZE + 1; ++blurCol) {
                int curRow = Row + blurRow;
                int curCol = Col + blurCol;

                // Verify pixel validity.
                if (curRow > -1 && curRow < h && curCol > -1 && curCol < w) {
                    pixVal += in[curRow * w + curCol];
                    pixels++; // Keep track of the number of pixels in the box for the average.
                }
            }
        }
        out[Row * w + Col] = (unsigned char) (pixVal / pixels); // Write the new pixel value.
    }
}