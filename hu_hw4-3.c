#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int smaller;

    if(a<b)
    {
        smaller = a;
    }
    else
    {
        smaller = b;
    }

    for(int i = smaller; i>0; i--)
    {
        if(b%i ==0&&a%i == 0)
        {
            printf("%d\n", i);
            exit(0);
        }
    }
    return 0;
}
