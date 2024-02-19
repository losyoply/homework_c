//TLE!
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* right, *left, *parent;
}Node;
Node* BSThead = NULL;
int num = 0;

Node* createNode(int a)
{
    Node* temp = calloc(1, sizeof(Node));
    temp->data = a;
    return temp;
}
int sumlevel(int input, Node* head)
{
    int sum = 0;
    if(head == NULL) return 0;
    if(input ==1)
    {
        num++;
        return head->data;
    }
    sum+= sumlevel(input-1, head->left);
    sum+= sumlevel(input-1, head->right);
    return sum;
}
double averlevel(int input, Node* head)
{
    double ans;
    num = 0;
    ans = (double)sumlevel(input, BSThead)/num;
    return ans;
}

Node* buildBST(int n)
{
    Node *head, *curr = NULL, *tmp, *root;
    int ww;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ww);
        tmp = createNode(ww);
        if(curr == NULL) head = curr = tmp;
        else if(tmp->data < curr->data){
            tmp->parent = curr;
            curr = curr->left = tmp;
        }
        else{
            root = curr;
            while(curr->parent != NULL && tmp->data > curr->parent->data){
                curr = curr->parent;
                if(curr->data > root->data) root = curr;
            }
            tmp->parent = root;
            curr = root->right = tmp;
        }
    }
    return head;
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
    if(head)
    {
        int leftdeep = get_max(head->left);
        int rightdeep = get_max(head->right);
        if(leftdeep>=rightdeep) deep = leftdeep+1;
        else deep = rightdeep+1;
    }
    return deep;
}

int main()
{
    int N, M;
    int a;
    char op[100];
    int input;
    scanf("%d", &N);
    BSThead = buildBST(N);

    scanf("%d", &M);

    for(int i = 0;i<M;i++)
    {
        scanf("%s", op);

        if(op[0]=='P')
        {
            if(BSThead==NULL) printf("NULL");
            else print_bst(BSThead);
        }
        else if(op[0] == 'G')
        {
            int height;
            height = get_max(BSThead);
            printf("%d", height);
        }
        else if(op[0] == 'S')
        {
            int ans;
            scanf("%d", &input);
            if(input>get_max(BSThead))
            {
                printf("0");
            }
            else
            {
                ans = sumlevel(input, BSThead);
                printf("%d",ans );
            }
        }
        else if(op[0]=='A')
        {
            double ans;
            scanf("%d", &input);
            if(input>get_max(BSThead))
            {
                printf("0");
            }
            else
            {
                ans = averlevel(input, BSThead);
                printf("%.3f", ans);
            }

        }
        printf("\n");
    }


}


