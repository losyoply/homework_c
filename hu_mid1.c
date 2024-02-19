#include<stdio.h>
int main()
{
    unsigned long long num;
    scanf("%llu", &num);
    unsigned long long ans[num];
    unsigned long long B[num];

    for(unsigned long long i = 0; i<num; i++)
    {
        scanf("%llu", &ans[i]);
    }
    for(unsigned long long i = 0; i<num; i++)
    {
        if(i==0)
        {
            B[i] = ans[i];
        }
        else
        {
            B[i] = ans[i] + B[i-1];
        }
    }
    scanf("%llu", &num);
    unsigned long long a, b;
    unsigned long long prin;
    for(unsigned long long i = 0; i<num; i++)
    {
        scanf("%llu %llu", &a ,&b);
        if(a==1)
        {
            prin = B[b-1];
        }
        else
        {
            prin = B[b-1] - B[a-2];
        }
        printf("%llu\n", prin);

    }
    return 0;
}
