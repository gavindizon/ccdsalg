#include <stdlib.h>
#include <time.h>

void GenerateData(int A[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        A[i] = rand() % N;
    }
}
