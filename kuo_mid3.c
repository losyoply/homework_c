//ok
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pos;
char expr[1000];
typedef struct Node
{
    char c;
    struct Node* left, *right;
}BTNode;
BTNode* EXPR();
BTNode* makeNode(char c)
{
    BTNode* temp = calloc(1, sizeof(BTNode));
    temp->c = c;
    return temp;
}

BTNode* FACTOR()
{
    char c;
    BTNode* node = NULL;
    c = expr[pos--];
    if(c>='A'&&c<='D')
    {
        node = makeNode(c);
    }
    else if(c==')')
    {
        node = EXPR();
        pos = pos-1;
    }
    return node;
}
BTNode* EXPR()
{
    char c;
    BTNode *node=NULL, *right=NULL;
    if(pos>=0)
    {
        right = FACTOR();
        if(pos>=0)
        {
            c = expr[pos];
            if(c=='&'||c=='|')
            {
                node = makeNode(c);
                node->right = right;
                pos = pos-1;

                node->left = EXPR();
            }
            else if(c=='(') node= right;
        }
        else node = right;
    }
    return node;
}
void printInfix(BTNode* root)
{
    BTNode* curr = root;
    if(curr!=NULL)
    {
        printInfix(curr->left);
        printf("%c", curr->c);
        if(curr->right&&(curr->right->c=='&'||curr->right->c=='|')) printf("(");
        printInfix(curr->right);
        if(curr->right&&(curr->right->c=='&'||curr->right->c=='|')) printf(")");
    }
}

int main()
{
    scanf("%s", expr);
    pos = strlen(expr)-1;
    BTNode *root = EXPR();
    printInfix(root);
}
