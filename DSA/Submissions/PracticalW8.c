/*
Develop C program to create an AVL Tree through a series of insertions from a predefined array of elements. Provide the following options for the said operations to be performed on the tree:
Insertion of a new element
Deletion of an existing element
Searching for a given element
Finding the width of the tree
Finding the max value and min value nodes
Listing the elements of the AVL in descending order
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
    int balance;
};


int queue[100];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == 99)
        return;
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
        rear++;
    queue[rear] = x;
}

int dequeue()
{
    int x = -1;
    if (front == -1 || front > rear)
        return x;
    x = queue[front];
    front++;
    return x;
}

int isEmpty()
{
    if (front == -1 || front > rear)
        return 1;
    return 0;
}





struct node *root = NULL;

struct node *LL(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    return pl;
}

struct node *RR(struct node *p)
{
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    return pr;
}

struct node *LR(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    return plr;
}

struct node *RL(struct node *p)
{
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    prl->lchild = p;
    return prl;
}

int height(struct node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->balance : 0;
    hr = p && p->rchild ? p->rchild->balance : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int balanceFactor(struct node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->balance : 0;
    hr = p && p->rchild ? p->rchild->balance : 0;
    return hl - hr;
}

struct node *insert(struct node *p, int key)
{
    struct node *t;
    if (p == NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = insert(p->lchild, key);
    else if (key > p->data)
        p->rchild = insert(p->rchild, key);
    p->balance = height(p);
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LL(p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LR(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return RR(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RL(p);
    return p;
}

struct node *inpre(struct node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

struct node *insuc(struct node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

struct node *delete (struct node *p, int key)
{
    struct node *q;
    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        q=inpre(p);
        if(q->lchild==p)
        {
            q->lchild=NULL;
        }
        else
        {
            q->rchild=NULL;
        }    
        free(p);
        return NULL;
    }
    if (key < p->data)
        p->lchild = delete (p->lchild, key);
    else if (key > p->data)
        p->rchild = delete (p->rchild, key);
    else
    {
        if (height(p->lchild) > height(p->rchild))
        {
            q = inpre(p->lchild);
            p->data = q->data;
            p->lchild = delete (p->lchild, q->data);
        }
        else
        {
            q = insuc(p->rchild);
            p->data = q->data;
            p->rchild = delete (p->rchild, q->data);
        }
    }
    p->balance = height(p);
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LL(p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LR(p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 0)
        return LL(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return RR(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RL(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 0)
        return RR(p);
    else if (balanceFactor(p) == 1 && balanceFactor(p->lchild) == 0)
        return LL(p);
    else if (balanceFactor(p) == -1 && balanceFactor(p->rchild) == 0)
        return RR(p);
    return p;
}

struct node *search(struct node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    else if (key < p->data)
        return search(p->lchild, key);
    else
        return search(p->rchild, key);
}

void descending(struct node *p)
{
    if (p)
    {
        descending(p->rchild);
        printf("%d ", p->data);
        descending(p->lchild);
    }
}

void inorder(struct node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

int max(struct node *p)
{
    if (p)
    {
        while (p->rchild != NULL)
            p = p->rchild;
        return p->data;
    }
    return -1;
}

int min(struct node *p)
{
    if (p)
    {
        while (p->lchild != NULL)
            p = p->lchild;
        return p->data;
    }
    return -1;
}

//find height of tree
int treeHeight(struct node *p)
{
    int x = 0, y = 0;
    if (p == NULL)
        return 0;
        else{
            x = treeHeight(p->lchild);
            y = treeHeight(p->rchild);
            if (x > y)
                return x + 1;
            else
                return y + 1;
        }
}

int getwidth(struct node *root, int level)
{
    if (root == NULL)
        return 0;
    if (level == 1)
        return 1;
    else
        return getwidth(root->lchild, level - 1) + getwidth(root->rchild, level - 1);
}

int maxwideth(struct node *root)
{
    int maxw = 0, width, h, i;
    h = treeHeight(root);
    for (i = 1; i <= h; i++)
    {
        width = getwidth(root, i);
        if (width > maxw)
            maxw = width;
    }
    return maxw;
}


int main(){
    int choice, key,n;
    //predifined tree
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 45);
    root = insert(root, 35);
    root = insert(root, 60);

    while (1)
    {
        printf("\n1. Insertion");
        printf("\n2. Deletion");
        printf("\n3. Search");
        printf("\n4. Width Of Tree");
        printf("\n5. Descending Order");
        printf("\n6. Max Value");
        printf("\n7. Min Value");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter key to be inserted: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter key to be deleted: ");
            scanf("%d", &key);
            root = delete (root, key);
            break;
        case 3:
            printf("Enter key to be searched: ");
            scanf("%d", &key);
            struct node *p;
            p = search(root, key);
            if (p != NULL)
                printf("Key %d is found", key);
            else
                printf("Key %d is not found", key);
            break;
        case 4:
            printf("Width of tree is %d", maxwideth(root));
            break;
        case 5:
            printf("Descending order is: ");
            descending(root);
            break;
        case 6:
            printf("Max value is %d", max(root));
            break;
        case 7:
            printf("Min value is %d", min(root));
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}


