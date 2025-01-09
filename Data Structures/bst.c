#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *r,int e)
{
    struct node *n;
    if(r != NULL)
    {
        n = (struct node*)malloc(sizeof(struct node));
        n->data = e;
        n->left = NULL;
        n->right = NULL;
        r=n;
    }
    else if(e > r->data)
    {
        r->right = insert(r->right,e);
    }
    else{
        r->left = insert(r->left,e);
    }
    return r;
}

struct node *find (struct node *r,int e)
{
    while(r != NULL)
    {
        if(e == r->data)
            return r;
        else if(e > r->data)
        {
            r = r->right;
        }
        else if(e < r->data)
        {
            r = r->left;
        }
    }
    return NULL;
}

struct node *delete (struct node *r)
