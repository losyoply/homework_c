//ok
#include<stdio.h>
#include<stdlib.h>
int A, B, C, D;
typedef struct Node
{
    char c;
    struct Node* right, *left;
}Node;
Node* createNode(char c)
{
    Node* temp = calloc(1, sizeof(Node));
    temp->c = c;
    return temp;
}
void buildtree(Node** head)
{
    char c;
    if((*head)==NULL)
    {
        (*head)=calloc(1, sizeof(Node));
        c = getchar();
        (*head)->c = c;
        if(c=='&'||c=='|')
        {
            buildtree(&(*head)->left);
            buildtree(&(*head)->right);
        }
    }
}

int solve(Node* root)
{
    int ans;
    //if(root==NULL) return;
    switch(root->c)
    {
        case 'A':
            return A;
            break;
        case 'B':
            return B;
            break;
        case 'C':
            return C;
            break;
        case 'D':
            return D;
            break;
        default:
            break;
    }
    int leftans, rightans;
    leftans = solve(root->left);
    rightans = solve(root->right);
    if(root->c == '&')
    {
        if(leftans==1&&rightans==1) ans = 1;
        else ans = 0;
    }
    else if(root->c=='|')
    {
        if(leftans==0&&rightans==0) ans = 0;
        else ans = 1;
    }
    return ans;
}

int main()
{
    int ans;
    Node* root = NULL;
    buildtree(&root);
    for(int a = 0;a<2;a++)
    {
        for(int b = 0;b<2;b++)
        {
            for(int c = 0;c<2;c++)
            {
                for(int d = 0;d<2;d++)
                {
                    A=a;B=b;C=c;D=d;
                    ans = solve(root);
                    printf("%d %d %d %d %d\n",A, B, C, D, ans);
                }
            }
        }
    }
}
