#include<stdio.h>
#include<stdlib.h>

typedef struct magic
{
    int num;
    struct magic* d[4];
} magic;
magic* create(int, int, magic*);
magic* create(int dir, int val, magic* pre)
{
    magic* fucku = malloc(sizeof(magic));
    fucku->num = val;
    fucku->d[dir] = pre;
    return fucku;
}
int Q, T;
int dir, val;

magic* cur, *start;
//cur = start = create(0,0,NULL);

int rdir[4] = {2,3,0,1};
int main()
{
    //magic* cur, *start;
    cur = start = create(0,0,NULL);
    scanf("%d", &Q);
    for(int i = 0;i<Q;i++)
    {
        scanf("%d", &T);
        if(T == 1)
        {
            scanf("%d %d", &dir, &val);
            cur->d[dir] = create(rdir[dir], val, cur);
        }
        else if(T==2)
        {
            scanf("%d", &dir);
            cur = cur->d[dir];
        }
        else if(T==3)
        {
            scanf("%d", &val);
            cur->num = val;
        }
        else if(T==4)
        {
            printf("%d\n", cur->num);
        }
    }
}
