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

    //handle runtime error
    if (A == NULL)
    {

        return result;
    }

    int *newA = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        newA[i] = A[i];
    }
    // write your code in C99 (gcc 6.2.0)

    if (K == N)
    {
        result.A = newA;
        result.N = N;
        result.K = K;
        return result;
    }
    else if ((K > N) && (K % N) == 0)
    {
        result.A = newA;
        result.N = N;
        result.K = K;
        return result;
    }
    else if (K == 0)
    {
        result.A = newA;
        result.N = N;
        result.K = K;
        return result;
    }

    //K < N Case

    int whichcase = (K % N);

    printf("whichcase = %d\n", whichcase);
    int MaxBound = (N - 1);
    //possible rotate case (N-1)
    int i = 0;
    int first = (N - whichcase);
    int idx = first;

    for (i = 0; i < N; i++)
    {
        if (i == 0)
        {
            newA[i] = A[first];
        }
        else
        {

            if (idx > MaxBound)
            {
                idx = 0;
                newA[i] = A[idx];
            }
            else
            {

                newA[i] = A[idx];
            }
        }
        idx++;
        //printAll(newA,N);
    }

    result.A = newA;
    result.N = N;
    result.K = K;
    printAll(newA, N);
    return result;
}

int main(void)
{
    int b = (0 % 1);
    printf("b=%d\n", b);

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