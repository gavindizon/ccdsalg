#define CPU_TIME  (1)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

unsigned long long iSortTime(int array[], int size, double *elapsedTime){
	long seconds, nanoseconds;
	struct timespec begin, end; 
	unsigned long long insertionCnt = 0;
		
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
		insertionCnt = insertionSort(array, size);   // <------ Insertion Sort
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   

	    seconds = end.tv_sec - begin.tv_sec;
	    nanoseconds = end.tv_nsec - begin.tv_nsec;
	    *elapsedTime += seconds + nanoseconds*1e-9;
	
	return insertionCnt;
}

unsigned long long hSortTime(int array[], int size, double *elapsedTime){
	long seconds, nanoseconds;
	unsigned long long heapCnt = 0;
	struct timespec begin, end; 

		
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
		heapCnt = heapSort(array, size);   // <------ Insertion Sort
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   

	    seconds = end.tv_sec - begin.tv_sec;
	    nanoseconds = end.tv_nsec - begin.tv_nsec;
	    *elapsedTime += seconds + nanoseconds*1e-9;
	
	return heapCnt;

}



int main() {
	
	int *mainData, *tempData;
	int i, j; 
	double elapsedTime[6];
	
		
	unsigned long long insertionCnt, heapCnt;
	int n = 1024; /// data size start
	srand((signed) time(NULL)); // Generate Data Initialization
	
	mainData = (int *)malloc(sizeof(int) * n); //Merge Sort
	tempData = (int *)malloc(sizeof(int) * n); //Heap Sort
	

	for(n = 1024; n < 500000; n*=2){
		printf("%d DATA SIZE:\n", n);
		mainData = (int *) realloc(mainData, sizeof(int) * n);
		tempData = (int *) realloc(tempData, sizeof(int) * n);
	
		insertionCnt = 0;
		heapCnt = 0;
	
	// Number of Trials per Data Size
		GenerateData(mainData, n);
		for(j = 0; j <  10; j++){
		//	printf("Trial %d for data size %d:\n", j+1, n);
			CopyData(mainData, tempData, n);
			insertionCnt = iSortTime(tempData, n, &elapsedTime[0]);
			CopyData(mainData, tempData, n);
			heapCnt = hSortTime(tempData, n, &elapsedTime[1]);
		    
//			    printf("CPU Time measured: %lf in seconds.\n", elapsed);
//			    printf("CPU Time measured: %lf in milliseconds.\n", elapsed * 1000);			
		}

		//Average Count
		printf("\nAVERAGE Count: \n");
		printf("Insertion Count: %lld\n", insertionCnt);
		printf("Heap Count: %lld\n", heapCnt);
		
		//Average Time
		printf("\nAVERAGE Time: \n");
		printf("Insertion Time: %lf in seconds\n", elapsedTime[0] / 10.0);
		printf("Heap Time: %lf in seconds\n\n", elapsedTime[1] / 10.0);

		
	}	

		free(mainData);
		free(tempData);
	
	return 0;
}
