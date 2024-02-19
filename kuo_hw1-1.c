#include<stdio.h>
#include<stdlib.h>

typedef struct card
{
    int idx;
    int data;
    struct card *next;
}card;

card* createcard(int data, int idx)
{
    card* temp=(card*)calloc(1, sizeof(card));;
    temp->data = data;
    temp->idx = idx;
    return temp;
}

void addcard(int idx, int num, card** headadd)
{
    card *head, *curr, *newcard;
    head = *headadd;
    newcard = createcard(num, idx);
    curr = head;
    if(idx == 0)
    {
            *headadd = newcard;
            newcard->next = head;
            curr = head;
            while(curr!= NULL)
            {
                curr->idx++;
                curr = curr->next;
            }
    }
    else
    {
        while(curr->next->idx!=idx)
        {
            curr = curr->next;
        }
        newcard->next = curr->next;
        curr->next = newcard;
        curr = curr->next->next;
        while(curr!=NULL)
        {
            curr->idx++;
            curr =curr->next;
        }

    }



}

void cutcard(int a, int b, card** headadd)
{
    if(a==0) return;
    card *n1, *n2, *n3;
    card *head, *curr;
    head = curr = *headadd;
    for(int i = 1;i<a;i++)
    {
        curr = curr->next;
    }
    n1 = curr;
    n2 = curr->next;
    curr = head;
    for(int i = 0;i<b;i++)
    {
        curr->idx+=curr->idx<a ? (b-a+1):(-a);
        curr = curr->next;
    }
    curr->idx+=curr->idx<a ? (b-a+1):(-a);
    n3 = curr;
    *headadd  = n2;
    n1->next = n3->next;
    n3->next = head;
}

void printcard(card* head)
{
    while(head!=NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main()
{
    int n,m;
    int a[10005];
    scanf("%d %d", &n, &m);
    for(int i = 0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    card *head, *curr;
    for(int i = 0;i<n;i++)
    {
        if(i==0) head = curr = createcard(a[i], i);
        else curr = curr->next = createcard(a[i],i);
    }
    char input[5];
    int para1, para2;
    for(int i = 0;i<m;i++)
    {
        scanf("%s %d %d", input, &para1, &para2);
        if(input[0]=='A') addcard(para1, para2, &head);
        else if(input[0] == 'C')
        {
            para2 = para1+para2-1;
            cutcard(para1, para2, &head);
        }
    }
    printcard(head);

}
