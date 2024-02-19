#include<stdio.h>
#include<stdlib.h>
void read_from_string(int* big, char* str, int len)
{

    for(int i = 0; i<len; i++)
    {
        big[i] = str[i] - '0';
    }

}

int bigger(int *a1, int *b1, int na, int nb)
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
        for(int i = 0; i<na;i++)
        {
            if(a1[i]>b1[i])
            {
                return 1;
            }
            else if(a1[i]<b1[i])
            {
                return 0;
            }
            else
            {
                printf("0");
                exit(0);

            }
        }
    }
}

void sub(int *a, int *b, int *c, int na, int nb)
{
    for  (int  i = na-1 ;  i <=0 ;  i --)
    {
        c [ i ] =  a [ i ] -  b [ nb-1 ];
        nb = nb -1;
    }

    for  (int  i = na-1 ;  i<=0 ;  i --)
    {

        if  ( c [i] <  0 )
        {
            c [ i - 1 ]--;
            c [ i ] +=  10 ;
        }
    }
        for(int i = 0; i<na-1;i++)
    {
         printf("%d", c[i]);
    }

}
int main()
{
    int na, nb;
    scanf("%d", &na);
    char a[na];
    int a1[na];
    scanf("%s", a);
    scanf("%d", &nb);
    char b[nb];
    int b1[nb];
    scanf("%s", b);
    read_from_string(a1, a, na);
    read_from_string(b1, b, nb);
    int ans[100]={};
    for(int i = 0; i<100; i++)
    {
        ans[i] = 10;
    }

    if(bigger(a1, b1, na, nb))
    {
        sub(a1, b1, ans, na, nb);

    }
    else
    {
       sub(b1, a1, ans, nb, na);
    }


    return 0;
}



