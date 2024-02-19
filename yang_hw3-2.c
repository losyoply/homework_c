#include<stdio.h>
int main()
{
    int in;
    int count=0;
    int x=0;
    int ans[100];
    scanf("%d", &in);
    in = in+1;

    while(in/2>0)
    {
        ans[x]=in%2;
        in = in/2;
        x = x+1;
    }
    printf("1");
    for(int i=x;i--;i>=0)
    {
        printf("%d",ans[i]);
        if(ans[i]==0)
        {
            count = count+1;
        }
        else if(ans[i]==1)
        {
            count=0;
        }
    }
    printf(" %d", count);

    return 0;
}
