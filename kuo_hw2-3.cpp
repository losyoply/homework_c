#include<stdlib.h>
#include<stdio.h>
#include <iostream>
#include <string>
#include "function.h"
using namespace std;
int tagID=0;
int szz = 0;
Node *createNode(int val)
{
	Node *tmp = ( Node*)calloc(1, sizeof(Node));
    tmp->val = val;
    tmp->tag = tagID;
    return tmp;
}
KuoYangPresent::KuoYangPresent(int k)
{
    this->k = k;
    szz=0;
    tail = NULL;
    mid = NULL;
}
void KuoYangPresent::Push(int x)
{
    if(szz==0) tail=NULL;
     Node *tmp = createNode(x);
    if(tail==NULL) head = tail = tmp;
    else
    {
        tmp->prev = tail;
        tail = tail->next = tmp;
    }
    szz++;
}
void KuoYangPresent::Pop()
{
    if(szz==0) return;
     Node *curr;
    int target =  (szz+1)/2;
    if(mid==NULL)
    {
        mid = head;
        for(int i = 1;i<target;i++) mid = mid->next;
    }
    else
    {
        for(int i = sz; i < target; i++) mid = mid->next;
    }
    curr = mid;
    if(szz%2)
    {
        sz = target - 1;
        mid = mid->prev;
    }
    else
    {
        sz = target;
        mid = mid->next;
    }
    if(curr->prev != NULL) curr->prev->next = curr->next;
    if(curr->next != NULL) curr->next->prev = curr->prev;
    free(curr);
    szz--;
}
void KuoYangPresent::ProgrammingTanoshi()
{
    tagID++;
}
void KuoYangPresent::KuoYangTeTe()
{
     Node *curr = head;
    while(curr!=NULL)
    {
        if(curr->tag < tagID)curr->val %= k;
        curr = curr->next;
    }
}
void KuoYangPresent::PrintList()
{
     Node *curr = head;
    while(curr!=NULL)
    {
        cout<<curr->val<<' ';
        curr = curr->next;
    }
	cout<<endl;
}
