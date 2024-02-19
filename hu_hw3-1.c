#include<stdio.h>
unsigned long long remem[117] = {};
unsigned long long stairs(int N)
{

    if(remem[N])
    {
        return remem[N];
    }
    else if(N==1||N==2||N==0)
    {
        return 1;
    }
    else if(N>2)
    {
        unsigned long long temp;
        temp = stairs(N-1) + stairs(N-3);
        remem[N] = temp;
        return temp;
    }

}

int main()
{

    int N;
    scanf("%d",&N);
    unsigned long long ans;
    ans = stairs(N);
    printf("%llu\n",ans);

    return 0;
}
