#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef struct mycomplex
{
    float real;
    float imag;
} COMPLEX;
extern "C" void cgesv_(int *,int *,COMPLEX *,int *,int *,COMPLEX *,int *,int *);

int main(int argc, char* argv[])
{

if (argc != 3){
cout<<"\n Insufficient Input Parameters";
exit(1);
}
int omegat=atoi(argv[1]);
double omega;
COMPLEX *x,*B,a,*A;
int i,j,N=5,info=0,lda=5,ipiv[4],ldb=5,N2=5,nrhs=1;
ofstream outfile;
outfile.open(argv[2]);

A=(COMPLEX *)calloc(25,sizeof(COMPLEX));
B=(COMPLEX *)calloc(N2,sizeof(COMPLEX));

for (omega=0;omega<omegat;omega+=1) {
double Xl=omega,Xc=1/(omega*2*pow(10,-6));
// inpiut matrix A
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
A[17].real=2; A[17].imag=Xl;
A[18].real=0; A[18].imag=0;
A[19].real=0; A[19].imag=0;

A[20].real=0; A[20].imag=0;
A[21].real=0; A[21].imag=0;
A[22].real=0; A[22].imag=0;
A[23].real=1; A[23].imag=0;
A[24].real=0; A[24].imag=Xc;

B[0].real=3.46; B[0].imag=2;
B[1].real=0; B[1].imag=0;
B[2].real=0; B[2].imag=0;
B[3].real=0; B[3].imag=0;
B[4].real=0; B[4].imag=0;

// calling cgesv from lapack library
cgesv_(&N2,&nrhs,A,&lda,ipiv,B,&ldb,&info);  
if (info)
	cout<<"You did something wrong in the parameters...please check that!\n";
else
  {
   cout<<B[0].real<<"+j"<<B[0].imag<<"\n";
   // V0 phase in radians
   float vtheta_rad = atan2(B[0].imag,B[0].real);   
   // V0 phase in degrees
   float vtheta_deg = (vtheta_rad/M_PI*180) + (vtheta_rad > 0 ? 0 : 360);  
   // V0 magnitude
   float vMagnitude = sqrt((B[0].real*B[0].real)+(B[0].imag*B[0].imag)); 
   // I0 phase in radians
   float itheta_rad = atan2(B[1].imag,B[1].real);		
   // I0 phase in degrees
   float itheta_deg = (itheta_rad/M_PI*180) + (itheta_rad > 0 ? 0 : 360);	
   // I0 magnitude   
   float iMagnitude = sqrt((B[1].real*B[1].real)+(B[1].imag*B[1].imag));		
outfile<<omega<<" "<<vMagnitude<<" "<<vtheta_rad<<" "<<iMagnitude<<" "<<itheta_rad
   <<endl;
  } 
}    // for loop ended 
return(0);
}
