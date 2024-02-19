#include<stdio.h>
int ans[1000] = {0};
void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(int* a, int s, int e)
{
    int f;

    if(s == e)
    {
        int sum = 0;
        for(int i = 1;i<=e;i++)
        {
            f = a[i];
            for(int h = 0;h<e-i;h++)
            {
                f = f*10;
            }
            sum = sum +f;
        }
        for(int i = 0;i<1000;i++)
        {
            if(ans[i]==0)
            {
                ans[i]=sum;
                break;
            }
        }
    }
        else
        {
            for(int i = s;i<=e;i++)
            {
                swap((a+s), (a+i));
                permute(a, s+1, e);
                swap((a+s), (a+i));
            }
        }
    }
int main()
{
    int N;
    scanf("%d", &N);
    int num[N+1];
    for(int i =1; i<=N;i++)
    {
        num[i] = i;
    }
    permute(num, 1, N);
    int times = 1;
    for(int i = N;i>=1;i--)
    {
        times = times*i;
    }
    int minn;
    int min;

    for(int ii=0;ii<times;ii++)
    {
        int chushu=1;
        for(int i = 0;i<N-1;i++)
        {
            chushu = chushu*10;
        }
        min = 999999;
        for(int i=0;i<1000;i++)
        {
            if(ans[i]<min&&ans[i]!=0)
            {
                min = ans[i];
                minn = i;
            }
        }
        while(chushu!= 0)
        {
            printf("%d ", min/chushu);
            min = min%chushu;
            chushu = chushu/10;
        }
        ans[minn] = 0;
        printf("\n");
    }
    return 0;
}
