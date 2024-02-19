#include<stdio.h>

int ccc(int x, int y)
{
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
    return ans;
}

int main()
{
    int a = ccc(2,2);
    printf("%d", a);
    return 0;
}
