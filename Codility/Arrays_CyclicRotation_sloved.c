#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Results
{

    int N;
    int *A;
    int K;
};
void printAll(int *, int);
struct Results solution(int A[], int N, int K)
{

    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    int *newA = (int *)malloc(sizeof(int) * N);
    //check runtime error
    if (A == NULL)
    {
        result.A = newA;
        result.N = N;
        return result;
    }

    for (int i = 0; i < N; i++)
    {
        int newPos = (i + K) % N;
        newA[newPos] = A[i];
    }
    printAll(newA,N);
    result.A = newA;
    result.N = N;
    return result;
}

int main(void)
{

    int array[1] = {1};
    //int *a = NULL;
    solution(array, 1, 0);

    system("PAUSE");
    return 0;
}

void printAll(int tmp[], int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("newA[%d]=%d\n", i, tmp[i]);
    }

    printf("--------------------\n");
}