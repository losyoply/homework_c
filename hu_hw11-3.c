#include<stdio.h>
#include<stdlib.h>
#define SWAP(a,b) {temp = a; a= b; b = temp;}
int temp;

typedef struct _Node {
    int data;


    struct _Node *next;
} Node;

Node* Merge_lists(Node*, Node*);

Node* Merge_lists(Node* x, Node* y)
{
    Node *start = NULL, *curr = NULL;
    int op;
    while(x!= NULL || y!= NULL)
    {
        if(curr == NULL) start = curr = calloc(1, sizeof(Node));
        else
        {
            while(x&&x->data == curr->data) x = x->next;
            while(y&&y->data == curr->data) y = y->next;
            if(x==NULL && y == NULL) break;
            curr = curr->next = calloc(1, sizeof(Node));
        }

        if(x!= NULL && y!=NULL)
        {
            if(x->data <= y->data) op = 1;
            else op = 2;
        }
        else if(x!= NULL) op = 1;
        else if(y!= NULL) op = 2;

        if(op ==1)
        {
            curr->data = x->data;
            x = x->next;
        }
        else
        {
            curr->data = y->data;
            y = y->next;
        }
    }
    return start;
}
