#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct node *insert(struct node *ptr, int key)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = key;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if (key < ptr->data)
    {
        ptr->lchild = insert(ptr->lchild, key);
    }
    else if (key > ptr->data)
    {
        ptr->rchild = insert(ptr->rchild, key);
    }
    else if (key == ptr->data)
    {
        printf("\nDuplicate key not allowed");
    }
    return ptr;
}

struct node *search(struct node *ptr, int key)
{
    if (ptr == NULL)
    {
        printf("\nKey not found");
        return NULL;
    }

    if (key < ptr->data)
    {
        return search(ptr->lchild, key);
    }
    else if (key > ptr->data)
    {
        return search(ptr->rchild, key);
    }
    else
    {
        printf("\nKey found");
        return ptr;
    }
}

void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        printf("%d ", ptr->data);
        inorder(ptr->rchild);
    }
}

void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void postorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d ", ptr->data);
    }
}

struct node *delete(struct node *ptr, int key)
{
    struct node *temp;
    if (ptr == NULL)
    {
        printf("\nKey not found");
        return NULL;
    }
    if (key < ptr->data)
    {
        ptr->lchild = delete(ptr->lchild, key);
    }
    else if (key > ptr->data)
    {
        ptr->rchild = delete(ptr->rchild, key);
    }
    else
    {
        if (ptr->lchild == NULL && ptr->rchild == NULL)
        {
            free(ptr);
            return NULL;
        }
        else if (ptr->lchild == NULL)
        {
            temp = ptr->rchild;
            free(ptr);
            return temp;
        }
        else if (ptr->rchild == NULL)
        {
            temp = ptr->lchild;
            free(ptr);
            return temp;
        }
        else
        {
            temp = ptr->rchild;
            while (temp->lchild != NULL)
            {
                temp = temp->lchild;
            }
            ptr->data = temp->data;
            ptr->rchild = delete(ptr->rchild, temp->data);
        }
    }
    return ptr;
}

int main()
{
    int choice, value;
    struct node *root = NULL;
    while (1)
    {
        printf("\n1.Insert");
        printf("\n2.Search");
        printf("\n3.Delete");
        printf("\n4.Inorder");
        printf("\n5.Preorder");
        printf("\n6.Postorder");
        printf("\n7.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nHow many nodes do you want to insert: ");
            scanf("%d", &value);
            int data;
            for (int i = 0; i < value; i++)
            {
                printf("\nEnter the data: ");
                scanf("%d", &data);
                root = insert(root, data);
            }
            break;
        case 2:
            printf("\nEnter the key to search: ");
            scanf("%d", &value);
            search(root, value);
            break;
        case 3:
            printf("\nEnter the key to delete: ");
            scanf("%d", &value);
            delete (root, value);
            break;
        case 4:
            printf("\nInorder traversal: ");
            inorder(root);
            break;
        case 5:
            printf("\nPreorder traversal: ");
            preorder(root);
            break;
        case 6:
            printf("\nPostorder traversal: ");
            postorder(root);
            break;
        case 7:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}

