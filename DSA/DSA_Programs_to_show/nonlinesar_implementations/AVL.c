//implement the AVL tree

// AVL tree

//insert, balance factor, rotation, delete

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
    int balance_factor;
};

struct node *root = NULL;

//search for the index of the root in inorder
int search(int inorder[], int start, int end, int data)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (inorder[i] == data)
            return i;
    }
}

//check if the tree is balanced
int isBalanced(struct node *p)
{
    int lh, rh;
    if (p == NULL)
        return 1;
    lh = height(p->lchild);
    rh = height(p->rchild);
    if (abs(lh - rh) <= 1 && isBalanced(p->lchild) && isBalanced(p->rchild))
        return 1;
    return 0;
}

//calculate the height of the tree
int height(struct node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

//calculate the balance factor
int balanceFactor(struct node *p)
{
    int lh, rh;
    if (p == NULL)
        return 0;
    lh = height(p->lchild);
    rh = height(p->rchild);
    return lh - rh;
}

//left rotation
struct node *LLRotation(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->balance_factor = balanceFactor(p);
    pl->balance_factor = balanceFactor(pl);
    if (p == root)
        root = pl;
    return pl;
}

//right rotation
struct node *RRRotation(struct node *p)
{
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->balance_factor = balanceFactor(p);
    pr->balance_factor = balanceFactor(pr);
    if (p == root)
        root = pr;
    return pr;
}

//left right rotation
struct node *LRRotation(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    p->balance_factor = balanceFactor(p);
    pl->balance_factor = balanceFactor(pl);
    plr->balance_factor = balanceFactor(plr);
    if (p == root)
        root = plr;
    return plr;
}

//right left rotation
struct node *RLRotation(struct node *p)
{
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    prl->lchild = p;
    p->balance_factor = balanceFactor(p);
    pr->balance_factor = balanceFactor(pr);
    prl->balance_factor = balanceFactor(prl);
    if (p == root)
        root = prl;
    return prl;
}


//insert
struct node *RInsert(struct node *p, int key)
{
    struct node *t = NULL;
    if (p == NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        t->balance_factor = 0;
        return t;
    }
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);
    p->balance_factor = balanceFactor(p);
    if (p->balance_factor == 2 && p->lchild->balance_factor == 1)
        return LLRotation(p);
    else if (p->balance_factor == 2 && p->lchild->balance_factor == -1)
        return LRRotation(p);
    else if (p->balance_factor == -2 && p->rchild->balance_factor == -1)
        return RRRotation(p);
    else if (p->balance_factor == -2 && p->rchild->balance_factor == 1)
        return RLRotation(p);
    return p;
}

//linsert
struct node *LInsert(struct node *p, int key)
{
    struct node *t = NULL;
    if (p == NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        t->balance_factor = 0;
        return t;
    }
    if (key > p->data)
        p->lchild = LInsert(p->lchild, key);
    else if (key < p->data)
        p->rchild = LInsert(p->rchild, key);
    p->balance_factor = balanceFactor(p);
    if (p->balance_factor == 2 && p->lchild->balance_factor == 1)
        return LLRotation(p);
    else if (p->balance_factor == 2 && p->lchild->balance_factor == -1)
        return LRRotation(p);
    else if (p->balance_factor == -2 && p->rchild->balance_factor == -1)
        return RRRotation(p);
    else if (p->balance_factor == -2 && p->rchild->balance_factor == 1)
        return RLRotation(p);
    return p;
}

//insert 
struct node *Insert(struct node *p, int key)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = key;
        root->lchild = root->rchild = NULL;
        root->balance_factor = 0;
        return root;
    }
    if (key < root->data)
        root->lchild = LInsert(root->lchild, key);
    else if (key > root->data)
        root->rchild = RInsert(root->rchild, key);
    root->balance_factor = balanceFactor(root);
    if (root->balance_factor == 2 && root->lchild->balance_factor == 1)
        return LLRotation(root);
    else if (root->balance_factor == 2 && root->lchild->balance_factor == -1)
        return LRRotation(root);
    else if (root->balance_factor == -2 && root->rchild->balance_factor == -1)
        return RRRotation(root);
    else if (root->balance_factor == -2 && root->rchild->balance_factor == 1)
        return RLRotation(root);
    return root;
}

/
