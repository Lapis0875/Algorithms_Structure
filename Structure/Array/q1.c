#include <stdio.h>
#include <stdlib.h>

void reverse_array(int size, int arr[], int start, int end);
void print_array(int size, int arr[]);

int main(void)
{
    int N, *arr;            // 원소 정보
    int cnt, start, end;  // 뒤집기 정보
    scanf("%d", &N);

    if (N < 3 || N > 100)
        return 0;

    arr = (int*) malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        scanf("%d ", arr + i);
    }

    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++)
    {
        scanf("%d %d", &start, &end);
        reverse_array(N, arr, start, end);
    }
    #ifdef DEBUG
        printf("===");
    #endif // DEBUG
    print_array(N, arr);
    return 0;
}

void reverse_array(int size, int arr[], int start, int end)
{
    int len = (end - start + 1) / 2, tmp;
    for (int i = 0; i < len; i++)
    {
        int self = start + i, opponent = end - i;
        tmp = arr[self];
        arr[self] = arr[opponent];
        arr[opponent] = tmp;

        #ifdef DEBUG
            print_array(size, arr);
        #endif // DEBUG
    }
}

void print_array(int size, int arr[])
{
    for (int i = 0; i < size; i ++)
    {
        printf("%d", arr[i]);
        putchar('\n' ? i == size - 1 : ' ');
    }
}