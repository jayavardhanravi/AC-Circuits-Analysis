#include <stdio.h>
#include <stdlib.h>

// declaration of structure
typedef struct mycomplex
{
      float real;
          float imag;
} COMPLEX;



extern int cgecon_(const char *norm, const int *n, COMPLEX *a, const int *lda, const double *anorm, double *rcond,COMPLEX *work, int *iwork, int *info, int len);
extern int cgetrf_(const int *m, const int *n, COMPLEX *a, const int *lda, int *iw, int *info);
extern double clange_(const char *norm, const int *m, const int *n, COMPLEX *a, const int *lda, COMPLEX *work, const int norm_len);

int main()
{
    int i, info=0,m,n, lda;
    double anorm, rcond;
    COMPLEX *A,*W;
    int iw[5];
    double w[5];
    n = 5;
    lda = 5;
    m=5;
    A=(COMPLEX *) calloc(25,sizeof(COMPLEX));     // creating space for A
    W=(COMPLEX *) calloc(5,sizeof(COMPLEX));

A[0].real=0; A[0].imag=0;
A[1].real=-1; A[1].imag=0;
A[2].real=-3; A[2].imag=0;
A[3].real=0; A[3].imag=0;
A[4].real=3; A[4].imag=0;

A[5].real=0; A[5].imag=0;
A[6].real=0; A[6].imag=0;
A[7].real=0; A[7].imag=0;
A[8].real=-1; A[8].imag=0;
A[9].real=0; A[9].imag=0;

A[10].real=1; A[10].imag=0;
A[11].real=2; A[11].imag=0;
A[12].real=-2; A[12].imag=0;
A[13].real=0; A[13].imag=0;
A[14].real=0; A[14].imag=0;

A[15].real=0; A[15].imag=0;
A[16].real=-2; A[16].imag=0;
A[17].real=2; A[17].imag=4;
A[18].real=0; A[18].imag=0;
A[19].real=0; A[19].imag=0;

A[20].real=0; A[20].imag=0;
A[21].real=0; A[21].imag=0;
A[22].real=0; A[22].imag=0;
A[23].real=1; A[23].imag=0;
A[24].real=0; A[24].imag=-2;

    /* Computes the norm of x */
    anorm = clange_("1", &n, &n, A, &lda, W, 1);
    /* Modifies x in place with a LU decomposition */
    cgetrf_(&n, &n, A, &lda, iw, &info);
 //   if (info != 0) fprintf(stderr, "failure with error %d\n", info);

    /* Computes the reciprocal norm */
    cgecon_("1", &n, A, &lda, &anorm, &rcond, W, iw, &info, 1);
 //   if (info != 0) fprintf(stderr, "failure with error %d\n", info);

    printf("%.5e\n",rcond);

    return 0;
}
