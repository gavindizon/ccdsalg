#define CPU_TIME  (1)
#define MAX 500000
#define START 1024

#include <stdio.h>
#include <stdlib.h>
#include "generator.c"
#include "bubble.c"
#include "merge.c"
#include "heap.c"
#include "insertion.c"
#include "selection.c"
#include "quick.c"
#include <inttypes.h>

typedef char String[52];


void CopyData(int A[], int B[], int N){
    int i;
    for (i = 0; i < N; i++){
        B[i] = A[i];
    }
}

unsigned long long bSortTime(int A[], int N, double *cpuTime){
    unsigned long long ctr; 

    // Start measuring time
    struct timespec begin, end; 


    // get start CPU time
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
 
    ctr = bubbleSort(A, N);
    
    // get end CPU time
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   


    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    *cpuTime += seconds + nanoseconds*1e-9;


    return ctr;
}

unsigned long long mSortTime(int A[], int N, double *cpuTime){
    unsigned long long ctr; 
    // Start measuring time
    struct timespec begin, end; 

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);

    /* NOTE: the next 5 lines are the computations being timed.  These lines should be replaced by a call to your sorting function. */
    ctr = rMergeSort(A, 0, N - 1);
    

    // get end CPU time
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   


    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    *cpuTime += seconds + nanoseconds*1e-9;

    return ctr;
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
unsigned long long sSortTime (int array[], int size, double *elapsedTime) {
	long seconds, nanoseconds;
	unsigned long long selectCnt = 0;
	struct timespec begin, end; 

		
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
		selectCnt = selectionSort(array, size);   // <------ Insertion Sort
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   

	    seconds = end.tv_sec - begin.tv_sec;
	    nanoseconds = end.tv_nsec - begin.tv_nsec;
	    *elapsedTime += seconds + nanoseconds*1e-9;
	
	return selectCnt;
}

unsigned long long qSortTime (int array[], int size, double *elapsedTime) {
	long seconds, nanoseconds;
	unsigned long long quickCnt = 0;
	struct timespec begin, end; 

		
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
		quickCnt = heapSort(array, size);   // <------ Insertion Sort
	    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   

	    seconds = end.tv_sec - begin.tv_sec;
	    nanoseconds = end.tv_nsec - begin.tv_nsec;
	    *elapsedTime += seconds + nanoseconds*1e-9;
	
	return quickCnt;
}

int main()
{
    int *mainData, *tempData;
    int N = START, M;
    int i;
    unsigned long long counters[6]; // change niyo na lang to 6 if pinagsama sama na 
    double cpuTimes[6] = {0, 0, 0, 0, 0, 0};
    String filenames[6] = { "results/bubblesort.txt", "results/mergesort.txt","results/insertionsort.txt","results/heapsort.txt", "results/selectionsort.txt", "results/quicksort.txt" };
    FILE *fp;

	for(i = 0; i < 6; i++){
		fp = fopen(filenames[i],"w");
		fclose(fp);
	}
	
    mainData = malloc(N * sizeof(int));
    tempData = malloc(N * sizeof(int));
    GenerateData(mainData, N);
	srand((unsigned) time(NULL)); // Generate Data Initialization
    
    for(N = START; N < MAX; N*=2){
    	printf("Executing at Data Size : %d... \n", N);
        mainData = (int *) realloc(mainData, N * sizeof(int));
        printf("Test 0");
        tempData = (int *) realloc(tempData, N * sizeof(int));
        
		printf("Test 1");
        GenerateData(mainData, N);
		printf("Test 2");
        
		for(M = 1; M <= 10; M++){
        	printf("Test A");
            CopyData(mainData, tempData, N);
            counters[0] = bSortTime(tempData, N, &cpuTimes[0]);
        	printf("Test B");
            CopyData(mainData, tempData, N);
			counters[1] = mSortTime(tempData, N, &cpuTimes[1]);
			printf("Test C");

			CopyData(mainData, tempData, N);
            counters[2] = iSortTime(tempData, N, &cpuTimes[2]);
            printf("Test D");
			CopyData(mainData, tempData, N);
			counters[3] = hSortTime(tempData, N, &cpuTimes[3]);
            CopyData(mainData, tempData, N);
            counters[4] = sSortTime(tempData, N, &cpuTimes[4]);
            CopyData(mainData, tempData, N);
			counters[5] = qSortTime(tempData, N, &cpuTimes[5]);

        }

        for(i = 0; i < 6; i++){
	        cpuTimes[i] /= 10;
            if((fp = fopen(filenames[i], "a"))!=NULL){
                fprintf(fp,"N: %d || counter: %llu || Average MET: %lf\n", N, counters[i], cpuTimes[i]);
            }
            else if((fp = fopen(filenames[i], "w"))){
                fprintf(fp,"N: %d || counter: %llu || Average MET: %lf\n", N, counters[i], cpuTimes[i]);
            }
            fclose(fp);
        }


    }

	printf("\n\nProgram Successfully Terminated\n\n");
    free(mainData);
    free(tempData);

    return 0;
} 
