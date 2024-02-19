#include<stdio.h>
#define MAXN 100
int N;
void permutation(int *arr, int idx)
{
    //ending condition
    if(idx > N)
    {
        return 0;
    }
    if(idx == N)
    {
        for(int i = 1; i <= N; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    int tmparr[MAXN];
    for(int j = idx; j <= N; j++)//j=i
    {
        tmparr[j] = arr[j];
    }

    for(int i = idx; i <= N; i++)
    {
        arr[idx] = tmparr[i];
        for(int j = 1; j <= i-idx; j++)
        {
            arr[idx+j] = tmparr[idx+j-1];
        }
        permutation(arr, idx+1);
        for(int j = idx; j <= N; j++)//j=i
        {
            arr[j] = tmparr[j];
        }
    }
}
int main()
{
    int arr[MAXN];
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) arr[i] = i;
    permutation(arr, 1);
    return 0;
}
