#include<stdio.h>
int main()
{
    int N, cnt[10005] = {};
    long long ans = 0, tmp;
    scanf("%d", &N);
    for(int i = 0, x; i<N; i++)
    {
        scanf("%d", &x);
        cnt[x] ++;
    }

    for(int i = 0;i<=10000; i++)
    {
        tmp = cnt[i];
        tmp = (cnt[i] - 1)*tmp;
        tmp = tmp/2;
        ans = ans + tmp;
    }
    printf("%d", ans);
    return 0;
}
