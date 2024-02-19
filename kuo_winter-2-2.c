#include<stdio.h>
#include<stdlib.h>
#define ll long long
typedef struct Node
{
    char c;
    int times, rodes;
    struct Node *next, *next2, *end;
    ll len;
}Node;

Node *createNode(char c)
{
    Node *temp = calloc(1, sizeof(Node));
    temp->c = c;
    temp->rodes = 1;
    return temp;
}

Node *addlist(Node *old)
{
    Node *head, *curr, *nodeO, *nodeu, *nodeQ;
    head  =  createNode('O');
    nodeO = head;
    head->next = old;
    old->end->next = nodeu = createNode('u');
    nodeu->next = old;
    head->end = old->end->next2 = nodeQ = createNode('Q');


    head->len = 2*(old->len) + 3;
    old->end->rodes = 2;

    return head;
}

void printList(Node *head, ll l, ll r)
{
    Node *curr = head;
    ll idx = 0;
    int tmp;
    while(curr!= head->end->next) //’ˆÓ”ñcurr->next!=head->end->next
    {
        if(idx>=l&&idx<=r) printf("%c", curr->c);

        if(curr->end != NULL &&(idx>r||(idx<l&&idx+curr->len - 1<l)))
        {
            idx += curr->len -1; //’ˆÓæˆÚ“®idx ÄˆÚ“®curr
            curr = curr->end;
        }
        else
        {
            tmp = curr->times;
            curr->times = (curr->times+1)%curr->rodes;
            if(tmp == 0) curr = curr->next;
            else if(tmp == 1) curr = curr->next2;
            idx++;
        }
        head->end->times = 0;
    }
    puts("");
}

int main()
{
    Node *head = createNode('O'), *curr;
    head->next = createNode('u');
    head->end = head->next->next = createNode('Q');
    head->len = 3;

    for(int i = 1; i<50;i++) head = addlist(head);

    int K, layer;
    ll L, R;
    while(scanf("%d %lld %lld", &K, &L, &R)!= EOF)
    {
        curr = head;
        layer = 50;
        while(layer-->K) curr = curr->next;
        printList(curr, L, R);
    }
}
