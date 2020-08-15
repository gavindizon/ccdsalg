#include <stdio.h>
#include <stdlib.h>


void GenerateData(int array[], int n){

	time_t t;
	int i = 0;
	
	srand((signed) time(&t));
	
	
	for(i=0; i < n; i++)
		array[i] = 	rand() % n;
	
}

void PrintData(int array[], int n){

	int i = 0;
		
		printf("[ ");
	for(i=0; i < n; i++)
		if(i != n -1)
			printf("%d, ", array[i]);
		else
			printf("%d ]\n", array[i]);
		
		printf("\n\n");	
}



int main() {
	
	int A[1024];
	int B[2048];
	int C[4096];
	
	
	GenerateData(A, 1024);
	GenerateData(B, 2048);
	GenerateData(C, 4096);
	
	
	PrintData(A, 1024);
	PrintData(B, 2048);
	PrintData(C, 4096);
	
	
	return 0;
}
