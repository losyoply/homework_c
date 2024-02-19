#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int i;
    struct Node* next, *prev;
    int come;
}Node;

Node* createNode(int i )
{
    Node *temp = (Node*)calloc(1, sizeof(Node));
    temp->i = i;
    return temp;
}

void solve(int lucknum, Node** head)
{
    Node *curr = *head;
    if(lucknum %2 == 1)
    {
        while(curr->come==1) curr = curr->next;
        for(int i = 0;i<lucknum-1;i++)
        {
            curr = curr->next;
            if(curr->come == 1) i=i-1;
        }
        curr->come = 1;
        printf("%d\n", curr->i);
        *head = curr;
    }
    else
    {
        while(curr->come==1) curr = curr->prev;
        for(int i = 0;i<lucknum-1;i++)
        {
            curr = curr->prev;
            if(curr->come ==1) i = i-1;
        }
        curr->come = 1;
        printf("%d\n", curr->i);
        *head = curr;
    }

}

int main()
{
    int a[100005];
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0;i<k;i++)
    {
        scanf("%d", &a[i]);
    }

    Node* head, *curr, *bef;  //搞出一個環
    for(int i = 1;i<=n;i++)
    {
        if(i ==1)  head = curr = bef= createNode(1);
        else
        {
            curr = curr->next = createNode(i);
            curr->prev = bef;
            bef = bef->next;
        }
    }
    curr->next = head;
    head->prev = curr;


    for(int i = 0;i<k;i++)
    {
        solve(a[i], &head);
    }
    return 0;
}
