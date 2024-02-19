#include<stdio.h>
int main()
{
    double a, b, ans;
    char op;

    scanf("%lf%c%lf", &a, &op, &b);


    switch(op)
    {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a-b;
        break;
    case '*':
        ans = a*b;
        break;
    case '/':
        if(b==0)
        {
            printf("Error\n");
            return 0;
        }
        ans = a/b;
        break;
    }
    printf("%.3f\n", ans);
    return 0;
}

