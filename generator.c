#include <stdlib.h>
#include <time.h>

void GenerateData(int A[], int N)
{
    int i;
    srand(time(0));
    for (i = 0; i < N; i++)
    {
        A[i] = rand() % N;
    }
}
