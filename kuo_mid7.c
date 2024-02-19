//ok
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
    int data;
    struct Node *right, *left;
}Node;
int searchVal(Node *root, int val)
{
    while(root!=NULL)
    {
        if(val==root->data)
        {
            return 1;
        }
        else if(val>root->data) root = root->right;
        else if(val<root->data) root = root->left;
    }
    return 0;
}
Node* createNode(int a)
{
    Node* temp = calloc(1, sizeof(Node));
    temp->data = a;
    return temp;
}
int sumlevel(int input, int level, Node* head)
{
    if(head==NULL||input==0) return 0;
    if(level<input)
    {
        int l = sumlevel(input, level+1, head->right);
        int r = sumlevel(input, level+1, head->left);
        return l+r;
    }
    else return head->data;
}
int countamount(Node *root, int level, int input)
{
    if(root==NULL||input ==0) return 0;
    if(level<input)
    {
        int l = countamount(root->left, level+1, input);
        int r = countamount(root->right, level+1, input);
        return l+r;
    }
    return 1;
}
void add_node(Node** BSThead,int data)
{
    Node* curr = *BSThead;
    if(curr == NULL)
    {
        *BSThead = createNode(data);
        return;
    }
    else
    {
        while(1)
        {
            if(data>=curr->data)
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

void print_bst(Node* head)
{
    Node* curr = head;
    if(curr==NULL) return;

    print_bst(curr->left);
    printf("%d ", curr->data);
    print_bst(curr->right);
}

int get_max(Node* head)
{
    int deep = 0;
    int leftdeep, rightdeep;
    if(head)
    {
        leftdeep = get_max(head->left);
        rightdeep = get_max(head->right);
        if(leftdeep>=rightdeep) deep = leftdeep+1;
        else deep = rightdeep+1;
    }
    return deep;
}

int main()
{
    Node* BSThead = NULL;
    int N, M;
    int a;
    char op[100];
    int input;
    scanf("%d", &N);
    for(int i = 0;i<N;i++)
    {
        scanf("%d", &a);
        if(searchVal(BSThead, a)) continue;///////////ŽùŸs
        else add_node(&BSThead,a);
    }
    scanf("%d", &M);

    for(int i = 0;i<M;i++)
    {
        scanf("%s", op);

        if(op[0]=='P')
        {
            static int done = 0;
            if(done)
            {
                continue;
            }
            done = 1;
            if(BSThead==NULL) printf("NULL");
            else print_bst(BSThead);
        }
        else if(op[0] == 'G')
        {
            static int done = 0;
            if(done)
            {
                continue;
            }
            done = 1;
            int height;
            height = get_max(BSThead);
            printf("%d", height);
        }
        else if(op[0] == 'S')
        {
            static Node* quer = NULL;
            int ans;
            scanf("%d", &input);
            if(searchVal(quer,input))
            {
                continue;
            }
            add_node(&quer,input);
            if(input>get_max(BSThead))
            {
                printf("0");
            }
            else
            {
                ans = sumlevel(input,1, BSThead);
                printf("%d",ans );
            }
        }
        else if(op[0]=='A')
        {
            static Node* quer = NULL;
            double ans;
            scanf("%d", &input);
            if(searchVal(quer, input))
            {
                continue;
            }
            add_node(&quer,input);
            if(input>get_max(BSThead)||input ==0)
            {
                printf("0");
            }
            else
            {
                int amount = countamount(BSThead, 1, input);
                ans = (double)sumlevel(input,1,BSThead)/amount;
                printf("%.3f", ans);
            }

        }
        printf("\n");
    }


}


