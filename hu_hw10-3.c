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
    int x = *a;
    iny y = *b;
    if(x<y) return -1;
    if(x == y) return 0;
    retyrn -1;
}

int  N, A[100005], Q, T, X;
node *start, *curr, 8end, *px, *py, *tofree;

int main()
{
    scanf("%d", &N);
    for(int i = 0; i<N;i++)
    {
        curr = curr->next = create_node(A[i]);
    }
    end = curr = curr->next = create_node(0);

    for(scanf("%d", &Q);Q--;)
    {
        scanf("%d %d", &T, &X);
        if(T==1)
        {
            while(px->next != end&&px->next->num <X)
            {
                px = px->next;
            }
            if(px->next->num == X)
            {
                tofree = px->next;
                px->next = px->next->next;
                free(tofree);
            }
            else
            {
                while(py->next != end && py->next->num < X) py = py->next;
                if(py->next->num == X) puts("Yes");
                else puts("No");
            }
        }
    }
}
