#include <stdio.h>
#include <stdlib.h>
 
 //inthreaded binary search tree
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;

    int lthread;
    int rthread;
};

struct node *root = NULL;

struct node *insert(struct node *root, int data)
{
    struct node *temp,*curr = root,*prev = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->lchild = NULL;
    temp->rchild = NULL;
    temp->lthread = 0;
    temp->rthread = 0;

    if(root == NULL)
    {
        root = temp;
        root->lchild = root;
        root->rchild = root;
        root->lthread = 1;
        root->rthread = 1;
        return root;
    }

    while(curr != NULL)
    {
        prev = curr;
        if(data < curr->data)
        {
            if(curr->lthread == 0)
                curr = curr->lchild;
            else
                break;
        }
        else
        {
            if(curr->rthread == 0)
                curr = curr->rchild;
            else
                break;
        }
    }

    if(data < prev->data)
    {
        temp->lchild = prev->lchild;
        temp->rchild = prev;
        prev->lchild = temp;
        prev->lthread = 0;
    }
    else
    {
        temp->rchild = prev->rchild;
        temp->lchild = prev;
        prev->rchild = temp;
        prev->rthread = 0;
    }
    return root;
}

//inorder successor
struct node *inorder_successor(struct node *root, struct node *curr)
{
    struct node *temp;
    if(curr->rthread == 1)
        return curr->rchild;
    else
    {
        temp = curr->rchild;
        while(temp->lthread == 0)
            temp = temp->lchild;
        return temp;
    }
}

//inorder predecessor
struct node *inorder_predecessor(struct node *root, struct node *curr)
{
    struct node *temp;
    if(curr->lthread == 1)
        return curr->lchild;
    else
    {
        temp = curr->lchild;
        while(temp->rthread == 0)
            temp = temp->rchild;
        return temp; 
    }
}

//deletion of node
struct node *delete(struct node *root, int data)
{
    struct node *curr = root,*prev = NULL,*temp,*succ,*pred;
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return root;
    }

    while(curr != NULL)
    {
        if(data == curr->data)
            break;
        prev = curr;
        if(data < curr->data)
        {
            if(curr->lthread == 0)
                curr = curr->lchild;
            else
                break;
        }
        else
        {
            if(curr->rthread == 0)
                curr = curr->rchild;
            else
                break;
        }
    }

    if(curr == NULL)
    {
        printf("Element not found\n");
        return root;
    }

    if(curr->lthread == 0 && curr->rthread == 0)
    {
        succ = inorder_successor(root,curr);
        curr->data = succ->data;
        prev = curr;
        curr = succ;
    }

    if(curr->lthread == 0)
        temp = curr->lchild;
    else
        temp = curr->rchild;

    if(prev == NULL)
    {
        root = temp;
        free(curr);
        return root;
    }   

    if(curr == prev->lchild)
    {
        prev->lchild = temp;
        prev->lthread = 1;
    }
    else
    {
        prev->rchild = temp;
        prev->rthread = 1;
    }

    if(curr->lthread == 1 && curr->rthread == 1)
    {
        pred = inorder_predecessor(root,curr);
        succ = inorder_successor(root,curr);
        pred->rchild = succ;
        succ->lchild = pred;
    }
    free(curr);
    return root;
}



int main()
{
    int choice, data;
    while(1)
    {
        printf("\n1.Insert");
        printf("\n2.Inorder");
        printf("\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                root = insert(root,data);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}

