#include<iostream>
#include"function.h"

using namespace std;
Array_MAX_HEAP::Array_MAX_HEAP()
{
    Count = 0;
}

void Array_MAX_HEAP::PUSH(const int &num)
{
    int n = ++Count;
    array[n] = num;
    while(n>1 && array[n]>array[n/2])
    {
        swap(array[n], array[n/2]);
        n = n/2;
    }
}
int Array_MAX_HEAP::MAX() const
{
    if(Count == 0) return -1;
    return array[1];
}
int Array_MAX_HEAP::POP()
{
    if(Count==0) return -1;
    int maxnum = array[1];
    int n = 1;
    array[1] = array[Count--];
    while((2*n<=Count&&array[n]<array[2*n])||(2*n+1<=Count&&array[n]<array[2*n+1]))
    {
        if(2*n+1>Count||array[2*n]>=array[2*n+1])
        {
            swap(array[n], array[2*n]);
            n =2*n;
        }
        else
        {
            swap(array[n], array[2*n+1]);
            n = 2*n+1;
        }
    }
    return maxnum;
}
List_MAX_HEAP::List_MAX_HEAP()
{
    Count = 0;
}
void List_MAX_HEAP::PUSH(const int &num)
{
    ListNode *newnode = new ListNode(num);
    if(Count ==0) root = newnode;
    else
    {
        int way[12] = {};
        int target = Count + 1;
        int iw = 0;
        ListNode *curr = root;
        while(target>1)
        {
            way[iw++] = target%2;
            target = target/2;
        }
        while(--iw>=1)
        {
            curr = way[iw]? curr->right:curr->left;
        }
        newnode->parent = curr;
        curr = (way[iw] ? curr->right:curr->left) = newnode;
        while(curr->parent&&curr->value>curr->parent->value)
        {
            swap(curr->value, curr->parent->value);
            curr = curr->parent;
        }
    }
    Count++;
    return;
}
int List_MAX_HEAP::MAX()const
{
    if(Count == 0) return -1;
    return root->value;
}
int List_MAX_HEAP::POP()
{
    if(Count==0) return -1;
    ListNode* curr, *todele;
    int maxnum = root->value;
    if(Count == 1)
    {
        todele = root;
        root = NULL;
    }
    else
    {
        int way[12]={}, target = Count, iw = 0;
        curr = root;
        while(target>1)
        {
            way[iw++] = target%2;
            target = target/2;
        }
        while(--iw>=1) curr = way[iw]? curr->right:curr->left;
        //iw=0
        //if(iw == 0){
        todele = way[iw] ? curr->right:curr->left;
        (way[iw]?curr->right : curr->left) = NULL;
        //}

    curr= root;
    curr->value = todele->value;
    while((curr->left&&curr->value<curr->left->value)||(curr->right&&curr->value<curr->right->value) )
    {
        if(curr->right&&curr->right->value>=curr->left->value)
        {
            swap(curr->value, curr->right->value);
            curr = curr->right;
        }
        else
        {
            swap(curr->value, curr->left->value);
            curr = curr->left;
        }
    }
    }

    delete todele;
    Count--;
    return maxnum;
}
void List_MAX_HEAP::deleteTree(ListNode *root)
{
    if(root==NULL) return;
    deleteTree(root->right);
    deleteTree(root->left);
    delete root;
}
