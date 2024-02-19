Node *buildBST(int n, int *preOrder)
{
    Node *head, *curr = NULL, *tmp, *root;
    for(int i = 0; i < n; i++)
    {
        tmp = createNode(preOrder[i]);
        if(curr == NULL) head = curr = tmp;
        else if(tmp->key < curr->key)
        {
            tmp->parent = curr;
            curr = curr->ltree = tmp;
        }
        else
        {
            root = curr;
            while(curr->parent != NULL && tmp->key > curr->parent->key)
            {
                curr = curr->parent;
                if(curr->key > root->key) root = curr;
            }
            tmp->parent = root;
            curr = root->rtree = tmp;
        }
    }
    return head;
}
