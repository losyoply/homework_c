#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int num;
    struct node* next;
}node;

node* create_node(int num)
{
    node* cur = malloc(sizeof(node));
    cur->num = num;
    cur->next = NULL;
    return cur;
}
int cmp(const void*a , const void* b)
{
    int x = *(int*)a;
    int y = *(int*)b;
    if(x>y) return 0;
    if(x == y) return 0;
    return 1;
}

int  N, A[100005], Q, X;
node *start, *curr, *end, *px, *tofree;
//px = curr = start = create_node(0);
int main()
{
    scanf("%d", &N);
    for(int i = 0; i<N;i++) scanf("%d", &A[i]);
    qsort(A, N, sizeof(int), cmp);
    px = curr = start = create_node(0);

    for(int i = 0; i < N; i++)
        curr = curr->next = create_node(A[i]);
    end = curr = curr->next = create_node(0);
    int count = 0;
    for(scanf("%d", &Q);Q--;)
    {
        scanf("%d", &X);


            while(px->next != end&&px->next->num > X)
            {
                count ++;
                px = px->next;
            }
            printf("%d\n", N-count);

    }
}

