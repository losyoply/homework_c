#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    int i, n;
    struct Node **next;
}Node;

int N, X[100001], Y[100001], cnt[100001];//cnt單純用來計算要calloc幾個給next
Node *ptr[100001];
int pick(int, int);

int main()
{
    scanf("%d", &N);
    for(int i = 1;i<N;i++)
    {
        scanf("%d %d", X+i, Y+i);
        cnt[X[i]]++;
    }
    for(int i = 1;i<=N;i++)
    {
        ptr[i] = calloc(1, sizeof(Node));
        ptr[i]->i = i;
        ptr[i]->next = calloc(cnt[i], sizeof(Node*));
    }
    for(int i =1;i<N;i++)
    {
        ptr[X[i]]->next[ptr[X[i]]->n] = ptr[Y[i]];
        ptr[X[i]]->n ++;
    }
    for(int i = 1;i<=N;i++)
    {
        printf("%d%c", pick(i, 0)-1, i==N?'\n':' ' );
    }
}

int pick(int idx, int last) //意味不明
{
    int cnt = 1;
    for(int a = 0; a <ptr[idx]->n;a++)
    {
        if(ptr[idx]->next[a]->i == last) continue;
        else cnt+=pick(ptr[idx]->next[a]->i, idx);
    }
    return cnt;
}
