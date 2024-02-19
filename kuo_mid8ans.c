#include<stdio.h>
#include<stdlib.h>
typedef struct _Node
{
    struct _Node *prev;//��prev��next �ۑ��SWA
    struct _Node *next;
    int val;
    int tag;
}Node;

int n, k, q;
Node *head=NULL;

int nodeCnt=0;
int tagID=0;


Node *createNode(int val)
{
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->val = val;
    tmp->tag = tagID;
    return tmp;
}
void push(int x)
{
    static Node *end=NULL;
    if(nodeCnt == 0) end = NULL;
    Node *tmp = createNode(x);
    if(end == NULL) head = end = tmp;
    else
    {
        tmp->prev = end;
        end = end->next = tmp;
    }
    nodeCnt++;
}
void pop(){
    if(nodeCnt == 0) return;
    static Node *mid = NULL;
    static int midID;
    Node *curr;
    int target = (nodeCnt + 1) / 2;
    if(mid == NULL)
    {
        mid = head;
        for(int i = 1; i < target; i++) mid = mid->next;
    }
    else
    {
        for(int i = midID; i < target; i++) mid = mid->next;
    }

    curr = mid;
    if(nodeCnt % 2)
    {
        midID = target - 1;
        mid = mid->prev;
    }
    else
    {
        midID = target;
        mid = mid->next;
    }
    if(curr->prev != NULL) curr->prev->next = curr->next;
    if(curr->next != NULL) curr->next->prev = curr->prev;
    free(curr);
    nodeCnt--;
}
void programming_tanoshi()
{
    tagID ++;
}
void KuoYangTeTe()
{
    Node *curr = head;
    while(curr != NULL)
    {
        if(curr->tag < tagID)curr->val %= k;
        curr = curr->next;
    }
}

///////
int main() {
	scanf("%d %d %d", &n, &k, &q);
	for (int i = 1; i <= n;  ++i) {
		int x;
		scanf("%d", &x);
		push(x);
	}
	while (q--) {
		char op[20];
		scanf("%s", op);
		if (op[1] == 'u') {
			int x;
			scanf("%d", &x);
			push(x);
		}
		else if (op[1] == 'o') {
			pop();
		}
		else {
			scanf(" %s", op);
			programming_tanoshi();
		}
	}
	KuoYangTeTe();
	PrintList();
}

void PrintList() {
	Node* res = head;
	while (res) {
		printf("%d ", res->val);
		res = res->next;
	}
	puts("");
}
