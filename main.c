#define CPU_TIME  (1)
#define MAX 500000
#define START 1024

#include <stdio.h>
#include "generator.c"
#include "bubble.c"
#include "merge.c"
#include "heap.c"

typedef char String[52];


void CopyData(int *A, int *B, int N){
    int i;
    for (i = 0; i < N; i++){
        B[i] = A[i];
    }
}

int bSortTime(int *A, int N, int M, double *cpuTime){
    unsigned long long int ctr; 

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

int mSortTime(int *A, int *temp, int N, int M, double *cpuTime){
    unsigned long long int ctr; 
    // Start measuring time
    struct timespec begin, end; 

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);

    /* NOTE: the next 5 lines are the computations being timed.  These lines should be replaced by a call to your sorting function. */
    ctr = mergeSort(A, temp, N);
    

    // get end CPU time
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   


    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    *cpuTime += seconds + nanoseconds*1e-9;

    return ctr;
}

int main()
{
    int *mainData, *tempData, *tempMerge;
    int N = START, M;
    int i;
    unsigned long long int counters[2]; // change niyo na lang to 6 if pinagsama sama na 
    double cpuTimes[2] = {0, 0};
    String filenames[2] = { "results/bubblesort.txt", "results/mergesort.txt" };
    FILE *fp;


    mainData = malloc(N * sizeof(int));
    tempData = malloc(N * sizeof(int));
    tempMerge = malloc(N * sizeof(int));
    GenerateData(mainData, N);
	srand((signed) time(NULL)); // Generate Data Initialization
    
    for(N = START; N < MAX; N*=2){
        mainData = realloc(mainData, N * sizeof(int));
        tempData = realloc(tempData, N * sizeof(int));
        tempMerge = realloc(tempMerge, N * sizeof(int));

        GenerateData(mainData, N);

        for(M = 1; M <= 10; M++){
            CopyData(mainData, tempData, N);
            counters[0] = bSortTime(tempData, N, M, &cpuTimes[0]);
            CopyData(mainData, tempData, N);
            counters[1] = mSortTime(tempData, tempMerge, N, M, &cpuTimes[1]);
        }
        cpuTimes[0] /= 10;
        cpuTimes[1] /= 10;
        for(i = 0; i < 2; i++){
            if((fp = fopen(filenames[i], "a"))!=NULL){
                fprintf(fp,"N: %d || counter: %lld || Average MET: %f\n", N, counters[i], cpuTimes[i]);
            }
            else if((fp = fopen(filenames[i], "w"))){
                fprintf(fp,"N: %d || counter: %lld || Average MET: %f\n", N, counters[i], cpuTimes[i]);
            }
            fclose(fp);
        }


    }
    free(mainData);
    free(tempData);
    free(tempMerge);

    return 0;
}