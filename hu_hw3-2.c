#include<stdio.h>
int ans[101] = {0};
int main()
{
    int n;
    scanf("%d", &n);

    for(int i =2; i<=n;i++)
    {
        int w = i;
        for(int a =2; a<= i;a++)
        {
            while(w%a==0)
            {
                w = w/a;
                ans[a] = ans[a] +1;
            }
        }

    }
    unsigned long long pri=1;
    for(int i =0; i<101;i++)
    {
        if(ans[i])
        {
            pri = pri*(ans[i]+1);

        }
    }
    printf("%llu", pri);
    return 0;
}
