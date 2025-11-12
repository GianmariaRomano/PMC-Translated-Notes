#include <malloc.h>
#include <stdio.h>
#include <omp.h>

#define ORDER 1000
#define AVAL 3.0
#define BVAL 5.0
#define TOL  0.001

int main(int argc, char **argv) {
  int Ndim, Pdim, Mdim;   // To define the dimensionality of A[N][P], B[P][M], C[N][M].
	int i,j,k;
	double *A, *B, *C, cval, err, errsq;
  double dN, mflops;
	double start_time, run_time;

	Ndim = ORDER;
	Pdim = ORDER;
	Mdim = ORDER;

  // Memory allocation.
  A = (double *)malloc(Ndim*Pdim*sizeof(double)); // Store A of size NxP.
  B = (double *)malloc(Pdim*Mdim*sizeof(double)); // Store B of size PxM.
  C = (double *)malloc(Ndim*Mdim*sizeof(double)); // Store C of size NxM.

  // Start by initializing the matrices.
	for (i=0; i<Ndim; i++)
		for (j=0; j<Pdim; j++)
			*(A+(i*Ndim+j)) = AVAL;

	for (i=0; i<Pdim; i++)
		for (j=0; j<Mdim; j++)
			*(B+(i*Pdim+j)) = BVAL;

	for (i=0; i<Ndim; i++)
		for (j=0; j<Mdim; j++)
			*(C+(i*Ndim+j)) = 0.0;

  // Perform matrix multiplication.
	start_time = omp_get_wtime();
  #pragma omp parallel for collapse(3)
	for (i=0; i<Ndim; i++) {
		for (j=0; j<Mdim; j++) {
			for(k=0;k<Pdim;k++) {
				// C(i,j) = sum(over k) A(i,k) * B(k,j)
				*(C+(i*Ndim+j)) += *(A+(i*Ndim+k)) *  *(B+(k*Pdim+j)); // Perform computations via pointers.
			}
		}
	}

  // Check the output.
	run_time = omp_get_wtime() - start_time;
 
	printf(" Order %d multiplication in %f seconds \n", ORDER, run_time);
    
  dN = (double)ORDER;
  mflops = 2.0 * dN * dN * dN/(1000000.0* run_time);
 
	printf(" Order %d multiplication at %f mflops\n", ORDER, mflops);

	cval = Pdim * AVAL * BVAL;
	errsq = 0.0;
	for (i=0; i<Ndim; i++){
		for (j=0; j<Mdim; j++){
			err = *(C+i*Ndim+j) - cval;
		    errsq += err * err;
		}
	}

	if (errsq > TOL) 
		printf("\n Errors in multiplication: %f",errsq);
	else
		printf("\n Hey, it worked");

	printf("\n all done \n");
}
