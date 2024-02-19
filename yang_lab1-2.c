#include<stdio.h>
int remem[101][101] = {};

int ccc(int x, int y)
{
    if(remem[x][y])
    {
        return remem[x][y];
    }
    int ans;
    if(x==1&&y==1)
    {
        return 1;
    }
    else if(y==0)
    {
        return 1;
    }
    else if(y==1)
    {
        return x;
    }
    else if(y==x-1)
    {
        return x;
    }
    else if(y==x)
    {
        return 1;
    }
    ans = ccc(x-1,y)+ccc(x-1,y-1);
    ans = ans%10007;
    remem[x][y]=ans;
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    int x[n];
    int y[n];
    for(int i = 0; i<n;i++)
    {
        scanf("%d", &x[i]);
    }
    for(int i = 0; i<n;i++)
    {
        scanf("%d", &y[i]);
    }
    int mme[n];
    for(int i = 0;i<n;i++)
    {
        mme[i] = ccc(x[i], y[i]);

    }
    long long int pri=1;
    for(int i = 0; i<n;i++)
    {
        pri = mme[i]*pri;
        pri = pri%10007;
    }
    printf("%lld\n", pri);
    return 0;
}
