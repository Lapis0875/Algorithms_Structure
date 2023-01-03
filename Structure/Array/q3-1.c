#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_array(int N, int **arr);

int main(void)
{
    int N = 0;
    scanf("%d", &N);

    int **arr;
    arr = (int**) malloc(N * sizeof(int*));
    if (arr == NULL)
        return -1;

    for (int i = 0; i < N; i ++)
    {
        arr[i] = malloc(N * sizeof(int));
        if (i % 2)  // backward
        {
            for (int j = N-1; j >= 0; j--)
            {
                arr[i][j] = (i + 1) * N - j;
                #ifdef DEBUG
                    printf("> value (%d, %d) = %d\n", i, j, arr[i][j]);
                #endif

            }
        }
        else    // forward
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = i * N + (j + 1);
                #ifdef DEBUG
                    printf("> value (%d, %d) = %d\n", i, j, arr[i][j]);
                #endif
            }
        }
    }
    print_array(N, arr);
    return 0;
}

void print_array(int N, int **arr)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            printf("%d", arr[i][j]);
            printf(j == N-1 ? "\n" : " ");
        }
}