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

long long iSortTime(int array[], int size){
	long seconds, nanoseconds;
	double elapsed = 0;
	struct timespec begin, end; 
	long long insertionCnt = 0;
		
	#if CPU_TIME
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	#else
	    clock_gettime(CLOCK_REALTIME, &begin);
	#endif    		
		insertionCnt = insertionSort(array, size);   // <------ Insertion Sort
	#if CPU_TIME 
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   
	#else
	   clock_gettime(CLOCK_REALTIME, &end);
	#endif
	    seconds = end.tv_sec - begin.tv_sec;
	    nanoseconds = end.tv_nsec - begin.tv_nsec;
	    elapsed += seconds + nanoseconds*1e-9;
	
	return insertionCnt;
}

long long hSortTime(int array[], int size){
	long seconds, nanoseconds;
	double elapsed = 0;
	long long heapCnt = 0;
	struct timespec begin, end; 

		
	#if CPU_TIME
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
	#else
	    clock_gettime(CLOCK_REALTIME, &begin);
	#endif    		
		heapCnt = heapSort(array, size);   // <------ Insertion Sort
	#if CPU_TIME 
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   
	#else
	   clock_gettime(CLOCK_REALTIME, &end);
	#endif
	    seconds = end.tv_sec - begin.tv_sec;
	    nanoseconds = end.tv_nsec - begin.tv_nsec;
	    elapsed += seconds + nanoseconds*1e-9;
	
	return heapCnt;

}



int main() {
	
	int *mainData, *tempData;
	int i, j; 
		
	long long insertionCnt, heapCnt;
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
			insertionCnt += iSortTime(tempData, n);
			CopyData(mainData, tempData, n);
			heapCnt += hSortTime(tempData, n);
		    
//			    printf("CPU Time measured: %lf in seconds.\n", elapsed);
//			    printf("CPU Time measured: %lf in milliseconds.\n", elapsed * 1000);			
		}

		//Average Count
		printf("\nAVERAGE Count: \n");
		printf("Insertion Count: %.3f\n", insertionCnt / 10.0);
		printf("Heap Count: %.3f\n", heapCnt / 10.0);
		
		//Average Time
		printf("\nAVERAGE Time: \n");
//		printf("Insertion Time: %lf in seconds\n", elapsed / 10.0);

		
	}	

		free(mainData);
		free(tempData);
	
	return 0;
}
