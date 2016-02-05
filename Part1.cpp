#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// declaration of structure
typedef struct mycomplex
{
    float real;
    float imag;
} COMPLEX;

extern "C" void cgesv_(int *,int *,COMPLEX *,int *,int *,COMPLEX *,int *,int *);

int main() // main starts here
{
COMPLEX *x,*B,a,*A;
int i,j,N=5,info=0,lda=5,ipiv[4],ldb=5,N2=5,nrhs=1;
string STRING,delimiter = "+j",token0,token1;
ifstream infile;

A=(COMPLEX *)calloc(25,sizeof(COMPLEX));  // storage for A matrix
B=(COMPLEX *)calloc(N2,sizeof(COMPLEX));  // storage for B matrix

infile.open ("matrix.txt");    // opening a file
for (i=0;i<25;i++)             // reading matrix A from the file
{
      getline(infile,STRING);
      int len=STRING.size();
      int lastPos = STRING.find_first_not_of(delimiter, 0);
      int pos = STRING.find_first_of(delimiter, lastPos);
      token0 = STRING.substr(0, STRING.find(delimiter));
      token1 = STRING.substr(pos+2,len-pos );
      float real=atof(token0.c_str());
      float imag=atof(token1.c_str());
      A[i].real=real;
      A[i].imag=imag; 
}


for (i=0;i<5;i++) // reading matrix B from file
{
      getline(infile,STRING);
      int len=STRING.size();
      int lastPos = STRING.find_first_not_of(delimiter, 0);
      int pos = STRING.find_first_of(delimiter, lastPos);
      token0 = STRING.substr(0, STRING.find(delimiter));
      token1 = STRING.substr(pos+2,len-pos );
      float real=atof(token0.c_str());
      float imag=atof(token1.c_str());
      B[i].real=real;
      B[i].imag=imag;
}
// Closing the file
infile.close(); 
// calling function cgesv from LAPACK library
cgesv_(&N2,&nrhs,A,&lda,ipiv,B,&ldb,&info);  
if (info)
	cout<<"You did something wrong in the parameters...please check that!\n";
   	else
     {
       	cout<<"We have a valid solution...just don't know if it's right or not\n";
       	for (i=0;i<N2;i++)
         cout<<B[i].real<<"+j"<<B[i].imag<<"\n";
     }  
return(0);
}
