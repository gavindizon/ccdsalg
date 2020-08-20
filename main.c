#include <stdio.h>
#include "generator.c"
// #include "bubble.c"
#include "merge.c"

int main()
{
    int *A, *B;
    int N = 100;
    int i;
    A = malloc(N * sizeof(int));
    B = malloc(N * sizeof(int));

    GenerateData(A, N);

    // printf("NOT SORTED\n");
    // for (i = 0; i < N; i++)
    //     printf("%d\n", *(A + i));

    mergeSort(A, B, N);

    // printf("SORTED\n");
    // for (i = 0; i < N; i++)
    //     printf("%d\n", *(A + i));

    free(A);
    free(B);

    return 0;
    // for(i)
}