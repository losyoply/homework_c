#include<stdio.h>
int main()
{
    char a, b;
    int c;
    scanf("%c %c%d", &a, &b, &c);
    int preans, ans;

    if((int)a >=97)
    {
        if(b == '+')
            {
                preans = a -c;
                ans = preans;
                if(preans>122 || preans<97)
                {
                    ans = preans + 26;
                }
            }
            else
            {
                preans = a +c;
                ans = preans;
                if(preans>122 || preans<97)
                {
                    ans = preans - 26;
                }
            }
        ans = ans - 32;
    }
    else
    {
        if(b == '+')
            {
                preans = a -c;
                ans = preans;
                if(preans>90 || preans<65)
                {
                    ans = preans + 26;
                }
            }
            else
            {
                preans = a +c;
                ans = preans;
                if(preans>90 || preans<65)
                {
                    ans = preans - 26;
                }
            }
        ans = ans + 32;
    }

    printf("%c\n", ans);
    return 0;

}
