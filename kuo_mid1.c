//2努力看懂
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char sym[6];
char expr[1000];
int pos;
typedef struct BTNode
{
    int data;
    struct BTNode* left, *right;
}BTNode;

BTNode* makeNode(char c) ;  // create a node without any child
BTNode* EXPR();  // parse an infix expression and generate a syntax tree
BTNode* FACTOR();  // use the parse grammar FACTOR = ID | (EXPR) to deal with parentheses
void printPrefix(BTNode *root);
void freeTree(BTNode *root);

BTNode* makeNode(char c)
{
    BTNode* temp = calloc(1, sizeof(BTNode));
    for(int i = 0;i<6;i++) if(c==sym[i]) temp->data = i;
    return temp;
}

BTNode* FACTOR()
{
    char c;
    BTNode *node = NULL;

    if(pos>=0) //or if(1)
    {
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
    }
    return node;
}

BTNode* EXPR()
{
    char c;
    BTNode *node = NULL, *right = NULL;

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
                pos--;//***

                node->left = EXPR();
            }
            else if(c=='(') node = right;
        }
        else node = right;////m,,m,mm,
    }
    return node;
}



//////////////////////////

int main(void){
    sym[0]='A';
    sym[1]='B';
    sym[2]='C';
    sym[3]='D';
    sym[4]='&';
    sym[5]='|';
    while (scanf("%s", expr)!=EOF)
    {
        pos = strlen(expr) - 1;
        BTNode *root = EXPR();
        printPrefix(root);
        printf("\n");
        freeTree(root);
    }

    return 0;
}

/* print a tree by pre-order. */
void printPrefix(BTNode *root){
    if (root != NULL) {
        printf("%c",sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

