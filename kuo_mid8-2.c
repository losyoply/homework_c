//WA
#include<stdio.h>
#include<stdlib.h>
typedef struct _Node
{
    struct _Node *prev;

    int val;
    int tag;
}Node;
Node* head;
int n, k,q;
int lenA;
int tagID;
Node *createNode(int val)
{
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp->val = val;
    tmp->tag = tagID;
    return tmp;
}
void push(int val)
{
    static Node* end = NULL;
    if(lenA==0) end = NULL;
    Node *tmp = createNode(val);
    if(end==NULL) head = end = tmp;
    else
    {
        tmp->prev = end;
        end = end->next = tmp;
    }
    lenA++;
}
void pop(){
    if(lenA == 0) return;
    static Node *mid = NULL;
    static int midID;
    Node *curr;
    int target = (lenA + 1) / 2;
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
    if(lenA % 2)
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
    lenA--;
}
void programming_tanoshi()
{
    tagID++;
}
void KuoYangTeTe()
{
    Node* curr = head;
    while(curr!= NULL)
    {
        if(curr->tag<tagID) curr->val %= k;
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
