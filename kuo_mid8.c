#include<stdio.h>
#include<stdlib.h>
int A[100005];
void push(int pushnum)
{

}
void pop()
{

}
void tanoshi()
{

}
int main()
{
    int lenA, K, tasks, pushnum;
    char op[60];
    scanf("%d %d %d", &lenA, &K, &tasks);
    for(int i = 0;i<lenA;i++) scanf("%d", &A[i]);

    for(int i = 0;i<tasks;i++)
    {
        scanf("%s",op );
        if(op[1]=='u') //push
        {
            scanf("%d", &pushnum);
            push(pushnum);
        }
        else if(op[1] == 'o') //pop
        {
            pop();
        }
        else if(op[1] == 'r') //programming tanoshi
        {
            tanoshi();
        }
    }
    for(int i = 0;i<lenA;i++)
    {
       if(i!=lenA-1) printf("%d ", A[i]);
        else printf("%d\n", A[i]);
    }
    return 0;
}
