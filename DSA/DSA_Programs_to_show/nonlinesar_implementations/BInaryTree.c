//take inorder and preorder and make a binary tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct node *root = NULL;

//create binary tree
struct node* create(int preorder[], int inorder[], int start, int end)
{
    static int preIndex = 0;
    int inIndex=0;

    //base case
    if (start > end)
        return NULL;

    //make the node    
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = preorder[preIndex++];
    t->lchild = t->rchild = NULL;

    //if the node is a leaf node
    if (start == end)
        return t;

    //search for the index of the root in inorder
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == t->data)
        {
            inIndex = i;
            break;
        }
    }

    //create the left and right subtree
    t->lchild = create(preorder, inorder, start, inIndex - 1);
    t->rchild = create(preorder, inorder, inIndex + 1, end);
    return t;
}

//inorder traversal
void inorderT(struct node *p)
{
    if (p!=NULL)
    {
        inorderT(p->lchild);
        printf("%d ", p->data);
        inorderT(p->rchild);
    }
}

//preorder traversal
void preorderT(struct node *p)
{
    if (p!=NULL)
    {
        printf("%d ", p->data);
        preorderT(p->lchild);
        preorderT(p->rchild);
    }
}

//postorder traversal
void postorder(struct node *p)
{
    if (p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}






//level order traversal
void levelorder(struct node *p)
{
    struct node *queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = p;
    while (front != rear)
    {
        p = queue[front++];
        printf("%d ", p->data);
        if (p->lchild)
            queue[rear++] = p->lchild;
        if (p->rchild)
            queue[rear++] = p->rchild;
    }
}

int main()
{
    int preorder[] = { 1, 2, 4, 5, 3, 6, 7 };
    int inorder[] = { 4, 2, 5, 1, 6, 3, 7 };
    int n = sizeof(preorder) / sizeof(preorder[0]);
    root = create(preorder, inorder, 0, n - 1);
    printf("\nInorder traversal of the constructed tree is ");
    inorderT(root);
    printf("\nPreorder traversal of the constructed tree is ");
    preorderT(root);
    printf("\nPostorder traversal of the constructed tree is ");
    postorder(root);

    printf("\nLevelorder traversal of the constructed tree is ");
    levelorder(root);
    return 0;
}
 
