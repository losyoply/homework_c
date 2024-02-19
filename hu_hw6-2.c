//Easiest version (Recursion)
#include<stdio.h>
int n, totw, w[30], v[30];
long long ans = 0;
void solve(int, int, long long);
int main()
{
    scanf("%d%d", &n, &totw);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &w[i], &v[i]);
    }
    solve(1, 0, 0);
    printf("%lld\n", ans);
}
void solve(int idx, int weight, long long value)
{
    if(idx == n+1)
    {
        if(value > ans)
        {
            ans = value;
        }
        return;
    }

            solve(idx+1, weight, value);

            if(weight + w[idx] > totw)
            {
                return;
            }
            else
            {
                solve(idx+1, weight + w[idx], value + v[idx]);
            }

}
