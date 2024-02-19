#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int na, nb;
void sub(int *a1, int *b1)
{
    if(na<nb)
    {
        int temp;
        temp = na;
        na = nb;
        nb = temp;
    }
    int ans[1111];
    for  (int  i = 0 ;  i <nb ;  i ++)
    {
        ans[i] = a1[i] - b1[i];
    }
    for(int i = nb; i<na; i++)
    {
        ans[i] = a1[i];
    }
    for(int i = 0; i<na;i++)
    {
        if(ans[i]<0)
        {
            ans[i+1] = ans[i+1] -1;
            ans[i] = ans[i] + 10;
        }
    }
    for(int i = na-1 ;i>=0; i--)
    {
        if(ans[i] != 0)
        {
            for(int x= i; x>=0; x--)
            {
                printf("%d", ans[x]);

            }
            exit(0);
        }
    }
}

int bigger(int *a1, int *b1)
{
    if(na>nb)
    {
        return 1;
    }
    else if(na<nb)
    {
        return 0;
    }
    else
    {
        for(int i = na-1; i>=0;i--)
        {
           if(a1[i]!=b1[i])
           {
               return a1[i]>b1[i];
           }
        }
        printf("0");
        exit(0);
    }
}


int main()
{
    scanf("%d", &na);
    char a[na];
    int a1[na];


    scanf("%s", a);

    for(int i = 0; i<na;i++)
    {
        a1[i] = a[na-i-1] -'0';
    }

    scanf("%d", &nb);
    char b[nb];
    int b1[nb];


    scanf("%s", b);

    for(int i = 0; i<nb;i++)
    {
        b1[i] = b[nb-i-1] -'0';
    }

    if(bigger(a1, b1))
    {
        sub(a1, b1);
    }
    else
    {
        printf("-");
        sub(b1, a1);
    }



    return 0;

}
