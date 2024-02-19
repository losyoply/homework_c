//ok

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    char data;
    struct Node* left, *right;
}Node;

void printInfix(Node *root)
{
    Node *curr = root;
    if(curr==NULL) return;
    printInfix(curr->left);
    printf("%c", curr->data);
    if(curr->right&&(curr->right->data=='&'||curr->right->data=='|')) printf("(");
    printInfix(curr->right);
    if(curr->right&&(curr->right->data=='&'||curr->right->data=='|')) printf(")");
}










//////////////////

void constructTree(Node** head)
{
    char c;

    if((*head)==NULL)
    {
        (*head) = (Node *)malloc(sizeof(Node));
		c = getchar();

		(*head)->data = c;

        (*head)->left = (*head)->right = NULL;

        if(c=='&' ||c=='|')
        {
            constructTree( &(*head)->left);
            constructTree( &(*head)->right);
        }

    }
}

void freeTree(Node *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);// the number of test cases

    while(n>0)
    {
        getchar();
        Node *root=NULL;
        constructTree(&root);// construct syntax tree
        printInfix(root);// you have to implement this function
        printf("\n");
        freeTree(root);
        --n;
    }

    return 0;
}
