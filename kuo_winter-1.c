#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node ** nd, int data);
Node* createList();

Node* createList()
{
    Node*head, *curr = NULL;
    int x;
    while(1)
    {
        scanf("%d", &x);
        if(x == -1) break;

        if(curr == NULL) head = curr = (Node*)calloc(1, sizeof(Node));
        else curr = curr->next = (Node*)calloc(1, sizeof(Node));
        curr->data = x;
    }
    return head;
}

void deleteNode(Node** nd, int data)
{
    Node* curr = (*nd), *tofree;
    if(data == 1)
    {
        if((*nd) == NULL) return;
        tofree = *nd;
        *nd = (*nd)->next;
    }
    else
    {
        data--;
        for(int i = 0;i<data-1&&curr->next;i++) curr = curr->next;
        if(curr->next == NULL) return;
        tofree = curr->next;
        curr->next = curr->next->next;
    }
    free(tofree);
}
