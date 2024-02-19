//12264
#include<iostream>
#include<string>

#define america 0
#define africa 1
#define japan 2
using namespace std;

class Node
{
public:
    int data;
    int country;
    Node* next;
    Node* prev;
    Node();
    Node(int d, int c);
};

class List
{
public:
    Node* head;
    Node* tail;
    Node* amer;
    Node* afri;
    Node* japa;
    List();
    void enqueue(int x);
    void dequeue();
    void printList();
};
Node::Node()
{

}
Node::Node(int d, int c)
{
    data = d;
    country = c;
    next = NULL;
    prev = NULL;
}

List::List()
{
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;

    amer = afri = japa = head;
}

void List::enqueue(int x)
{
    Node* newnode = new Node(x, x%3);

    if(head->next == tail)
    {
        head->next = newnode;
        tail->prev = newnode;
        newnode->next = tail;
        newnode->prev = head;
        if(newnode->country==america)
        {
            amer = newnode;
        }
        else if(newnode->country==africa)
        {
            afri = newnode;
        }
        else
        {
            japa = newnode;
        }
        return;
    }
    if(newnode->country== america)
    {
        if(amer==head)
        {
            newnode->next= tail;
            newnode->prev = tail->prev;
            tail->prev->next = newnode;
            tail->prev = newnode;
        }
        else
        {
            newnode->next = amer->next;
            newnode->prev = amer;
            amer->next->prev = newnode;
            amer->next = newnode;
        }
        amer = newnode;
    }
    else if(newnode->country==africa)
    {
        if(afri==head)
        {
            newnode->next= tail;
            newnode->prev = tail->prev;
            tail->prev->next = newnode;
            tail->prev = newnode;
        }
        else
        {
            newnode->next = afri->next;
            newnode->prev = afri;
            afri->next->prev = newnode;
            afri->next = newnode;
        }
        afri = newnode;
    }
    else
    {
        if(japa==head)
        {
            newnode->next= tail;
            newnode->prev = tail->prev;
            tail->prev->next = newnode;
            tail->prev = newnode;
        }
        else
        {
            newnode->next = japa->next;
            newnode->prev = japa;
            japa->next->prev = newnode;
            japa->next = newnode;
        }
        japa = newnode;
    }
}

void List::dequeue()
{
    if(head->next==tail)
    {
        cout<<endl;
        return;
    }
    Node* tmp = head->next;
    cout<<tmp->data<<endl;

    if(tmp->country==america)
    {
        if(amer==tmp) amer= head;
        head->next = tmp->next;
        tmp->next->prev = head;
    }
    else if(tmp->country== africa)
    {
        if(afri==tmp) afri= head;
        head->next = tmp->next;
        tmp->next->prev = head;
    }
    else
    {
        if(japa==tmp) japa= head;
        head->next = tmp->next;
        tmp->next->prev = head;
    }
    delete tmp;
}

int main()
{
	int n = 0;
	int x = 0;
    List* mylist = new List();


    string cmd;
    cin >> n;
	while(n--)
    {
		cin >> cmd;
		if(cmd[0] == 'E')
        {
			cin >> x;
			mylist->enqueue(x);
		}
		else
			mylist->dequeue();
	}

	return 0;
}
