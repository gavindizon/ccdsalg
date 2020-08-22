#include <stdio.h>
#include <stdlib.h>
#include "insertion.c"
#include "heap.c"

void GenerateData(int array[], int n){

	int i = 0;
	
	for(i=0; i < n; i++)
		array[i] = 	rand() % n;
	
}

// Debugging Purposes
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

//from A to B
void CopyData(int A[], int B[], int N){
	int i;
	
	for(i = 0; i < N; i++)
		B[i] = A[i];
	
	
	
}



int main() {
	
	int *A, *B;
	int i, j; 
	
	double insertionCnt, heapCnt;
	
	int n = 1024;
	srand((signed) time(NULL)); // Generate Data Initialization
		
	A = (int *)malloc(sizeof(int) * n); //Merge Sort
	B = (int *)malloc(sizeof(int) * n); //Heap Sort
	

	for(n = 1024; n < 1025; n*=2){
		printf("%d DATA SIZE:\n", n);
		A = (int *) realloc(A, sizeof(int) * n);
		B = (int *) realloc(B, sizeof(int) * n);
	
		insertionCnt = 0;
		heapCnt = 0;
	
	// Number of Tries per Data Size
		for(j = 0; j <  10; j++){
			printf("Trial %d for data size %d:\n", j+1, n);
			
			GenerateData(A, n);
			CopyData(A, B, n);
			
			
			
			insertionCnt += insertionSort(A, n);
			heapCnt += heapSort(B, n);
		}

		//Average Count
		printf("\nAVERAGE Count: \n");
		printf("Insertion Count: %.3f\n", insertionCnt / 10.0);
		printf("Heap Count: %.3f\n", heapCnt / 10.0);
		
		//Average Time

		
	}	

		free(A);
		free(B);
	
	return 0;
}
