#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

//scalar variable n
int n = 1048576; //n = 2^20
//int n = 16777216; //n = 2^24
//int n = 268435456; //n = 2^28


//asm function to pass scalar variable n
extern int asm_LENGTH(int n); 

//asm function to pass scalar variable A, X, Y, and Z
extern float asm_SAXPY(float A, float* X, float* Y, float* Z_asm); 

//c function to call SAXPY function
void c_SAXPY(float A, float* X, float* Y, float* Z_c);


//function to perform SAXPY
void c_SAXPY(float A, float* X, float* Y, float* Z_c) {
	for (int i = 0; i < n; i++) {
		Z_c[i] = A * X[i] + Y[i];
	}
}


int main() {
	//data initialization
	float A = 2.0;
	float* X = (float*)malloc(n*sizeof(float));
	float* Y = (float*)malloc(n*sizeof(float));
	float* Z_c = (float*)malloc(n*sizeof(float));
	float* Z_asm = (float*)malloc(n*sizeof(float));
	bool check;
	clock_t c_start_time, c_end_time, asm_start_time, asm_end_time;
	float c_time, asm_time;

	//check if memory allocation was successful
	if (X == NULL || Y == NULL || Z_c == NULL || Z_asm == NULL) {
		printf("MALLOC FAILED\n");
		return 1;
	}

	for (int i = 0; i < n; i++) {
		if (i % 3 == 0) {
			X[i] = 1.0;
			Y[i] = 11.0;
		}
		else if (i % 3 == 1) {
			X[i] = 2.0;
			Y[i] = 12.0;
		}
		else {
			X[i] = 3.0;
			Y[i] = 13.0;
		}
	}


	//call to c function for SAXPY
	c_start_time = clock();
	c_SAXPY(A, X, Y, Z_c);
	c_end_time = clock();
	c_time = ((float)(c_end_time - c_start_time)) / CLOCKS_PER_SEC;

	
	//call to asm function to pass n and SAXPY
	asm_LENGTH(n);
	asm_start_time = clock();
	asm_SAXPY(A, X, Y, Z_asm);
	asm_end_time = clock();
	asm_time = ((float)(asm_end_time - asm_start_time)) / CLOCKS_PER_SEC;


	//memory deallocation of scalar variable X and Y
	free(X);
	free(Y);


	//print values, if asm values is the same to c then print "the x86-64 kernel output is correct"
	//output of first ten elements of array Z_c and Z_asm
	printf("Sanity check answer key: C version\n");
	printf("Values of Z_c:\n");
	for (int i = 0; i < 10; i++) {
		printf("%.2f ", Z_c[i]);
	}
	printf("\nExecution time: %.3f seconds\n", c_time);
	printf("\n\n");

	printf("Asnwer key to be checked: x86_64 version\n");
	printf("Values of Z_asm:\n");
	for (int i = 0; i < 10; i++) {
		printf("%.2f ", Z_asm[i]);
	}
	printf("\nExecution time: %.3f seconds\n", asm_time);
	printf("\n\n");
	
	//sanity check if the values of Z_asm is the same with Z_c
	for (int i = 0; i < n; i++) {
		if (Z_c[i] != Z_asm[i]) {
			check = false;
		}
		else {
			check = true;
		}
	}

	//output of sanity check result
	if (check == true) {
		printf("The x86-64 kernel output is correct\n");
	}
	else {
		printf("The x86-64 kernel output is incorrect\n");
	}

	free(Z_c);
	free(Z_asm);

	return 0;
}