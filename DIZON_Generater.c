#include <stdio.h>
#include <stdlib.h>
#include "insertion.c"

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
	
	int *A;
	int x = 24, y = 48, z = 96;
	
	A = (int *)malloc(sizeof(int) * x);
	GenerateData(A, x);
	PrintData(A, x);
	insertionSort(A, x);
	PrintData(A, x);

	free(A);
	A = (int *)malloc(sizeof(int) * z);
	
	GenerateData(A, z);
	PrintData(A, z);

	free(A);

	A = (int *)malloc(sizeof(int) * y);
	
	GenerateData(A, y);
	PrintData(A, y);
	
	
	free(A);
	
	
	return 0;
}
