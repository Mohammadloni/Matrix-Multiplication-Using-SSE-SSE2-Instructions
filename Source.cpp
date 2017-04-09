#include <stdio.h>
#include <stdlib.h>
#include <xmmintrin.h>
#include "time.h"
#include <time.h>

#define size1 64
#define size2 512
#define size3 1024
#define size4 2048
#define max 32768

void aligned_free(void *p)
{
    free(((void**)p)[-1]);
}

void show(int A[size4][size4],int n)
{	int i=0 ,j=0;
while(i<n){
while(j<n)
{printf("%i ", A[i][j]);j=j+1;}
printf(" \n");	j=0;i=i+1;	}
}//////////////////////////////////////////////////
void simplemul1( int n){
float sum=0;
int i=0 ,j=0,k=0;

float **A2=(float**)malloc(size4*sizeof(float*));
for(i=0;i<size4;i++)
	A2[i]=(float*)malloc(size4*sizeof(float));
float **B2=(float**)malloc(size4*sizeof(float*));
for(i=0;i<size4;i++)
	B2[i]=(float*)malloc(size4*sizeof(float));
float **C2=(float**)malloc(size4*sizeof(float*));
for(i=0;i<size4;i++)
	C2[i]=(float*)malloc(size4*sizeof(float));
float **D2=(float**)malloc(size4*sizeof(float*));
for(i=0;i<size4;i++)
	D2[i]=(float*)malloc(size4*sizeof(float));
i=0;
for (i = 0; i <n; i++) {
for (j = 0; j <n; j++) {
sum = 0;
for (k = 0; k < n; k++) {
sum = sum + A2[i][k] * B2[k][j];
}
C2[i][j] = sum;  }
}
	free(A2);
	free(B2);
	free(C2);
	free(D2);
}

////////////////////////////////////////////////////////////////
void simplemul(int n){int sum=0;
int i=0 ,j=0,k=0;
int **A=(int**)malloc(size4*sizeof(int*));
for(i=0;i<size4;i++)
	A[i]=(int*)malloc(size4*sizeof(int));
int **B=(int**)malloc(size4*sizeof(int*));
for(i=0;i<size4;i++)
	B[i]=(int*)malloc(size4*sizeof(int));
int **C=(int**)malloc(size4*sizeof(int*));
for(i=0;i<size4;i++)
	C[i]=(int*)malloc(size4*sizeof(int));
int **D=(int**)malloc(size4*sizeof(int*));
for(i=0;i<size4;i++)
	D[i]=(int*)malloc(size4*sizeof(int));
i=0;

srand ( (time(NULL)) );
for (i = 0; i <n; i++)
for (j = 0; j <n; j++)
{A[i][j] =rand() % max;
B[i][j]=rand() % max;
}
for (i = 0; i <n; i++) {
for (j = 0; j <n; j++) {
sum = 0;
for (k = 0; k < n; k++) {
sum = sum + A[i][k] * B[k][j];
}
C[i][j] = sum;  }
}
	free(A);
	free(B);
	free(C);
	free(D);
}
////////////////////////////////////////////////////////////////
void simplemul2( int n){
double sum=0;
int i=0 ,j=0,k=0;
double **A3=(double**)malloc(size4*sizeof(double*));
for(i=0;i<size4;i++)
	A3[i]=(double*)malloc(size4*sizeof(double));
double **B3=(double**)malloc(size4*sizeof(double*));
for(i=0;i<size4;i++)
	B3[i]=(double*)malloc(size4*sizeof(double));

double **C3=(double**)malloc(size4*sizeof(double*));
for(i=0;i<size4;i++)
	C3[i]=(double*)malloc(size4*sizeof(double));

double **D3=(double**)malloc(size4*sizeof(double*));
for(i=0;i<size4;i++)
	D3[i]=(double*)malloc(size4*sizeof(double));
i=0;


srand ( (time(NULL)) );
for (i = 0; i <n; i++)
{  for (j = 0; j <n; j++)

{	A3[i][j] =(double)rand() / 32767;
B3[i][j]	=(double)rand() /32767;
}	srand ( (time(NULL)) );}
for (i = 0; i <n; i++) {
for (j = 0; j <n; j++) {
sum = 0;
for (k = 0; k < n; k++) {
sum = sum + A3[i][k] * B3[k][j];
}
C3[i][j] = sum;  }
}
	free(A3);
	free(B3);
	free(C3);
	free(D3);
}
////////////////////////////////////////////////////////////
void* aligned_malloc(size_t required_bytes, size_t alignment)
{
    void* p1; // original block
    void** p2; // aligned block
    int offset = alignment - 1 + sizeof(void*);
    if ((p1 = (void*)malloc(required_bytes + offset)) == NULL)
    {
       return NULL;
    }
    p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1));
    p2[-1] = p1;
    return p2;
}
/////////////////////////////////////////////////////////////
void ssemul1(int n){
	int i = 0, j = 0, k = 0;

float **A2=(float**)aligned_malloc(size4*sizeof(float*),16);
for(i=0;i<size4;i++)
	A2[i]=(float*)malloc(size4*sizeof(float));
float **B2=(float**)aligned_malloc(size4*sizeof(float*),16);
for(i=0;i<size4;i++)
	B2[i]=(float*)malloc(size4*sizeof(float));
float **C2=(float**)aligned_malloc(size4*sizeof(float*),16);
for(i=0;i<size4;i++)
	C2[i]=(float*)malloc(size4*sizeof(float));
float **D2=(float**)aligned_malloc(size4*sizeof(float*),16);
for(i=0;i<size4;i++)
	D2[i]=(float*)malloc(size4*sizeof(float));
i=0;
//float A2[size4][size4], B2[size4][size4], C2[size4][size4], D2[size4][size4]; __attribute__((aligned(16)));// for Static Allocation
	srand(unsigned(time(0)));
	
for (i = 0; i < n; i++)
		for (j =0 ; j <n; j++)
		{
		A2[i][j] = float(i+1);
		B2[i][j] = float(j + 1);
		C2[i][j] = 0;
		}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			D2[i][j] = B2[j][i];
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
		{
			__m128 *m3 = (__m128*)A2[i];
			__m128 *m4 = (__m128*)D2[j];
			float* res;
			C2[i][j] = 0;
			for (k = 0; k < n ; k += 4 ){
				__m128 m5 = _mm_mul_ps(*m3, *m4);
				res = (float*)&m5;
				C2[i][j] += res[0] + res[1] + res[2] + res[3];
				m3++;
				m4++;
			}
		}
	}

	aligned_free(A2);
	aligned_free(B2);
	aligned_free(C2);
	aligned_free(D2);
}
//////////////////////////////////////////////////////////////////////
void sse2mul(int n){
	int i = 0, j = 0, k = 0;

double **A3=(double**)aligned_malloc(size4*sizeof(double*),16);
for(i=0;i<size4;i++)
	A3[i]=(double*)malloc(size4*sizeof(double));
double **B3=(double**)aligned_malloc(size4*sizeof(double*),16);
for(i=0;i<size4;i++)
	B3[i]=(double*)malloc(size4*sizeof(double));
double **C3=(double**)aligned_malloc(size4*sizeof(double*),16);
for(i=0;i<size4;i++)
	C3[i]=(double*)malloc(size4*sizeof(double));
double **D3=(double**)aligned_malloc(size4*sizeof(double*),16);
for(i=0;i<size4;i++)
	D3[i]=(double*)malloc(size4*sizeof(double));
i=0;	
for (i = 0; i <n; i++)
{  for (j = 0; j <n; j++)

{	A3[i][j] =(double)rand() / ((i+1)*max);
B3[i][j] = (double)rand() / ((j + 1)*max);
}	
}
for (int i = 0; i < n; ++i)
{
	for (int j = 0; j < n; ++j)
	{
		D3[i][j] = B3[j][i];
	}
}

for (i = 0; i <n; i++) {
for (j = 0; j <n; j++) {
	__m128 *m3 = (__m128*)A3[i];
	__m128 *m4 = (__m128*)D3[j];
	double* res;
	C3[i][j] = 0;
	for (k = 0; k < n/2; k++) {
	__m128 m5 = _mm_mul_ps(*m3,*m4);
res = (double*)&m5;
C3[i][j] += res[0]+res[1]+res[2]+res[3];
m3++;
m4++;}
}
}	
}
//////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{	clock_t tv1, tv2;
	
	tv1=clock();
	simplemul(size1);
	tv2=clock();
	printf("Total time simplemul int 64 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);
	tv1=clock();
	simplemul(size2);
	tv2=clock();
	printf("Total time simplemul int 512 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);
	tv1=clock();
	simplemul(size3);
	tv2=clock();
	printf("Total time simplemul int 1024= %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);
	tv1=clock();
	simplemul(size4);
	tv2=clock();
	printf("Total time simplemul int 2048 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);
///////////////////////
	tv1=clock();
	simplemul1(size1);
	tv2=clock();
	printf("Total time simplemul float 64 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);
	tv1=clock();
	simplemul1(size2);
	tv2=clock();
	printf("Total time simplemul float 512 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);
	tv1=clock();
	simplemul1(size3);
	tv2=clock();
	printf("Total time simplemul float 1024 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);
	tv1=clock();
	simplemul1(size4);
	tv2=clock();
	printf("Total time simplemul float 2048 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);
///////////////////////////////////////////////////
	tv1=clock();
	simplemul2(size1);
	tv2=clock();
	printf("Total time simplemul double 64 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);	
	tv1=clock();
	simplemul2(size2);
	tv2=clock();
	printf("Total time simplemul double 512 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);	
	tv1=clock();
	simplemul2(size3);
	tv2=clock();
	printf("Total time simplemul double 1024 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);	
	tv1=clock();
	simplemul2(size4);
	tv2=clock();
	printf("Total time simplemul double 2048= %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);	
/////////////////////////////////////////////////
	tv1=clock();
	ssemul1(size1);
	tv2=clock();
	printf("Total time sse float 64 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);
	tv1=clock();
	ssemul1(size2);
	tv2=clock();
	printf("Total time sse float 512 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);	
	tv1=clock();
	ssemul1(size3);
	tv2=clock();
	printf("Total time sse float 1024 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);	
	tv1=clock();
	ssemul1(size4);
	tv2=clock();
	printf("Total time sse float 2048 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);	

///////////////////////
	tv1=clock();
	sse2mul(size1);
	tv2=clock();
	printf("Total time sse2 double 64 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);	
	tv1=clock();
	sse2mul(size2);
	tv2=clock();
	printf("Total time sse2 double 512 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);
	tv1=clock();
	sse2mul(size3);
	tv2=clock();
	printf("Total time sse2 double 1024 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);
	tv1=clock();
	sse2mul(size4);
	tv2=clock();
	printf("Total time sse2 double 2048 = %.2f ms\n",(double)(tv2-tv1) * 1000.0/CLOCKS_PER_SEC);

	return 0;
}
