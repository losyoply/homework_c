//ok...çƒóDâª
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int val;
    struct Node* next;
}Node;
Node* createNode(int val)
{
    Node* temp = calloc(1, sizeof(Node));
    temp->val = val;
    return temp;
}
void do_I(Node** head, int pos, int val)// ok
{
    Node* h, *curr, *newn;
    h = curr= *head;
    if(pos==0||h ==NULL)
    {
        *head = createNode(val);
        if(pos == 0)
        {
            (*head)->next = h;
        }
    }
    else
    {
        newn = createNode(val);
        for(int i = 0;i<pos-1&&curr->next!=NULL;i++)
        {
             curr = curr->next;
        }
        newn->next = curr->next;
        curr->next = newn;
    }
}
void do_E(Node **head,int begin_pos,int end_pos)//#‡£
{
    if(*head==NULL||begin_pos==end_pos) return;
    end_pos = end_pos-1;
    Node *h = *head, *curr, *n1, *n2;
    curr = h;
    if(begin_pos==0)
    {
        for(int i = 0;i<end_pos+1&&curr!=NULL;i++) curr = curr->next;
        *head = curr;
    }
    else
    {
        for(int i = 0;i<begin_pos-1&&curr->next!=NULL;i++) curr = curr->next;
        if(curr->next==NULL) return;
        n1 = curr;
        curr = h;
        for(int i = 0;i<end_pos+1&&curr!=NULL;i++) curr = curr->next;
        n2 = curr;

        n1->next = n2;
    }


}
void do_P(Node *head,int pos)
{
    Node *curr = head;
    if(curr == NULL) return;
    for(int i = 0;i<pos&&curr->next!=NULL;i++)
    {
        curr = curr->next;
    }
    printf("%d ", curr->val);
}
void do_R(Node **head,int val)
{
    Node *h = *head, *curr, *n1;
    curr = h;
    if(curr==NULL) return;//óÒï\à◊ãÛ
    if(h->val==val)
    {
        while(curr&&curr->val==val) curr = curr->next;
        *head = curr;
        if(curr==NULL) return;//êÆå¬ï\ìsRù{
    }
    curr = *head;
    while(curr->next!=NULL)
    {
        if(curr->next->val == val)
        {
            n1 = curr;
            while(curr->next!=NULL&&curr->next->val==val) curr = curr->next;
            n1->next = curr->next;

            curr = *head;
        }
        else curr = curr->next;
    }
}

void do_S(Node *head)//ok
{
    Node *curr = head;
    while(curr!= NULL)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
}












//////////////
int main(void)
{
	Node *head=NULL;
	size_t N;
	scanf("%zu",&N);
	while(N--)
	{
		char op;
		unsigned short val;
		size_t pos,begin_pos,end_pos;
		scanf(" %c",&op);
		switch(op)
		{
		case 'I':
			scanf("%zu %hu",&pos,&val);
			do_I(&head,pos,val);
			break;
		case 'E':
			scanf("%zu %zu",&begin_pos,&end_pos);
			do_E(&head,begin_pos,end_pos);
			break;
		case 'P':
			scanf("%zu",&pos);
			do_P(head,pos);
			break;
		case 'R':
			scanf("%hu",&val);
			do_R(&head,val);
			break;
		case 'S':
			do_S(head);
			break;
		}
	}
            return 0;
}
