#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_array(int N, int arr[N][N]);

int main(void)
{
    int N = 0;
    scanf("%d", &N);

    int (*arr)[N];
    arr = (int(*)[N]) malloc((N * N) * sizeof(int));
    if (arr == NULL)
        return -1;

    for (int i = 0; i < N; i ++)
    {
        if (i % 2)  // backward
        {
            for (int j = N; j > 0; j--)
                arr[i][j] = (i + 1) * N + (N + 1 - j);
        }
        else    // forward
        {
            for (int j = 0; j < N; j++)
                arr[i][j] = (i + 1) * N + (j + 1);
        }
    }
    print_array(N, arr);
    return 0;
}

void print_array(int N, int arr[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            printf("%d", arr[i][j]);
            putchar('\n' ? j == N-1 : ' ');
        }
}