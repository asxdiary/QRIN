#include "lapacke.h"

void Testext_lapack_inverse(double* A, int N)
{
    int *IPIV = new int[N+1];
    int LWORK = N*N;
    double *WORK = new double[LWORK];
    int INFO;

    dgetrf_(&N,&N,A,&N,IPIV,&INFO);
    dgetri_(&N,A,&N,IPIV,WORK,&LWORK,&INFO);

    delete [] IPIV;
    delete [] WORK;
}

int Testext_lapack_main(){

    double A [2*2] = {
        1,2,
        3,4
    };

    Testext_lapack_inverse(A, 2);

    /**
    printf("%f %f\n", A[0], A[1]);
    printf("%f %f\n", A[2], A[3]);
    */

    return 0;
}
