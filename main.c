#define CPU_TIME  (1)

#include <stdio.h>
#include "generator.c"
#include "bubble.c"
#include "merge.c"



void CopyData(int *A, int *B, int N){
    int i;
    for (i = 0; i < N; i++){
        B[i] = A[i];
    }
}

void bSortTime(int *A, int N, int M){
    double sum = 0;
    double add = 1;
    int i;
    int ctr; 

    // Start measuring time
    struct timespec begin, end; 

#if CPU_TIME

    // get start CPU time
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);

#else

    clock_gettime(CLOCK_REALTIME, &begin);

#endif    

    /* NOTE: the next 5 lines are the computations being timed.  These lines should be replaced by a call to your sorting function. */
    ctr = bubbleSort(A, N);
    
    // Stop measuring time and calculate the elapsed time
#if CPU_TIME 

    // get end CPU time
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   

#else

   clock_gettime(CLOCK_REALTIME, &end);

#endif

    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;
    printf("BUBBLE SORT TEST # %d N = %d\n", M, N);
    printf("counter: %d\n", ctr);
    
    printf("CPU Time measured: %lf in seconds.\n", elapsed);
    printf("CPU Time measured: %lf in milliseconds.\n", elapsed * 1000); // multiply seconds by 1000 to get milliseconds
    printf("------------------------------------------------------------------------------\n");

}

void mSortTime(int *A, int *temp, int N, int M){
    double sum = 0;
    double add = 1;
    int i;
    int ctr; 

    // Start measuring time
    struct timespec begin, end; 

#if CPU_TIME

    // get start CPU time
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);

#else

    clock_gettime(CLOCK_REALTIME, &begin);

#endif    

    /* NOTE: the next 5 lines are the computations being timed.  These lines should be replaced by a call to your sorting function. */
    ctr = mergeSort(A, temp, N);
    
    // Stop measuring time and calculate the elapsed time
#if CPU_TIME 

    // get end CPU time
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   

#else

   clock_gettime(CLOCK_REALTIME, &end);

#endif

    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;
    printf("MERGE SORT TEST # %d N = %d\n", M, N);
    printf("counter: %d\n", ctr);
    
    printf("CPU Time measured: %lf in seconds.\n", elapsed);
    printf("CPU Time measured: %lf in milliseconds.\n", elapsed * 1000); // multiply seconds by 1000 to get milliseconds
    printf("------------------------------------------------------------------------------\n");

}

int main()
{
    int *mainData, *tempData, *tempMerge;
    int N = 8, M;
    int ctr;
    mainData = malloc(N * sizeof(int));
    tempData = malloc(N * sizeof(int));
    tempMerge = malloc(N * sizeof(int));
    GenerateData(mainData, N);
 
    for(N = 8; N <= 16; N*=2){
        mainData = realloc(mainData, N * sizeof(int));
        tempData = realloc(tempData, N * sizeof(int));
        tempMerge = realloc(tempMerge, N * sizeof(int));

        GenerateData(mainData, N);

        for(M = 1; M <= 10; M++){
            CopyData(mainData, tempData, N);
            // ctr = mergeSort(tempData, tempMerge, N);
            bSortTime(tempData, N, M);
            CopyData(mainData, tempData, N);
            mSortTime(tempData, tempMerge, N, M);
        }
        printf("%d\n", ctr);

    }

    return 0;
    // for(i)
}