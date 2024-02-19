#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int i;
    struct Node* next, *prev;
    int come;
}Node;
Node *head;
Node* createNode(int i )
{
    Node *temp = (Node*)calloc(1, sizeof(Node));
    temp->i = i;
    return temp;
}
Node* createList(int num)
{
    Node *head, *curr, *bef;  //搞出一個環
    for(int i = 1;i<=num;i++)
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
    return head;
}
void solve(int lucknum, Node** head,int num)
{
    Node *curr = *head;
    if(lucknum %2 == 1)
    {
        lucknum = lucknum%num;
        if(lucknum == 0) lucknum = num;
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
        lucknum = lucknum%num;
        if(lucknum == 0) lucknum = num;
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
void solveJosephus(int num, int tasks)
{
    int lucknum;
    for(int i = 0;i<tasks;i++)
    {
        scanf("%d", &lucknum);
        solve(lucknum, &head,num);
        num = num-1;
    }
}



int main(){

    int n, k;

    while(scanf("%d%d", &n, &k)!=EOF){
        head = createList(n);
        solveJosephus(n, k);
    }

    return 0;
}
