#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    struct Node *right, *left;
    int data;
}Node;

Node *tree_head=NULL;
Node* createNode(int data)
{
    Node* temp = calloc(1, sizeof(Node));
    temp->data = data;
    return temp;
}
void add_node(int data)
{
    Node *curr =tree_head;
    if(tree_head == NULL)
    {
        tree_head = createNode(data);
        return;
    }
    else
    {
        while(1)
        {
            if(data>curr->data)
            {
                if(curr->right == NULL)
                {
                    curr->right = createNode(data);
                    return;
                }
                curr = curr->right;
            }
            else if(data<curr->data)
            {
                if(curr->left== NULL)
                {
                    curr->left = createNode(data);
                    return;
                }
                curr = curr->left;
            }
        }

    }
}

void showtree(Node* root)
{
        Node* curr = root;
        if(curr == NULL) return;
        showtree(curr->left);
        printf("%d ", curr->data);
        showtree(curr->right);
}








int main(){
    int n, a;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);
        add_node(a);
    }
    showtree(tree_head);
}
