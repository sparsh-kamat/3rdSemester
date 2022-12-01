#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *lchild;
    boolean lthread;
    struct node *rchild;
    boolean rthread;    
};

struct node *root = NULL;

//inorder successor
struct node *inorderSucc(struct node *ptr)
{
    struct node *temp = ptr->rchild;
    if (ptr->rthread == false)
    {
        while (temp->lthread == false)
        {
            temp = temp->lchild;
        }
    }
    return temp;
}

//inorder predecessor
struct node *inorderPred(struct node *ptr)
{
    struct node *temp = ptr->lchild;
    if (ptr->lthread == false)
    {
        while (temp->rthread == false)
        {
            temp = temp->rchild;
        }
    }
    return temp;
}

//insert
struct node* insert(struct node* root, int ikey){
    struct node *temp, *ptr, *par;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ikey;
    temp->lthread = true;
    temp->rthread = true;
    par = NULL;
    ptr = root;

    while (ptr != NULL)
    {
        par = ptr;
        if (ikey < ptr->data)
        {
            if (ptr->lthread == false)
            {
                ptr = ptr->lchild;
            }
            else
            {
                break;
            }
        }
        else if (ikey > ptr->data)
        {
            if (ptr->rthread == false)
            {
                ptr = ptr->rchild;
            }
            else
            {
                break;
            }
        }
        else
        {
            printf("\nDuplicate key not allowed");
            return root;
        }
    }

    if (par == NULL)
    {
        root = temp;
        temp->lchild = NULL;
        temp->rchild = NULL;
    }
    else if (ikey < par->data)
    {
        temp->lchild = par->lchild;
        temp->rchild = par;
        par->lthread = false;
        par->lchild = temp;
    }
    else
    {
        temp->lchild = par;
        temp->rchild = par->rchild;
        par->rthread = false;
        par->rchild = temp;
    }
}

//delete
struct node* delete(struct node* root, int dkey){
    struct node *par, *ptr, *succ, *parsucc, *temp;
    par = NULL;
    ptr = root;

    while (ptr != NULL)
    {
        if (dkey == ptr->data)
        {
            break;
        }
        par = ptr;
        if (dkey < ptr->data)
        {
            if (ptr->lthread == false)
            {
                ptr = ptr->lchild;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (ptr->rthread == false)
            {
                ptr = ptr->rchild;
            }
            else
            {
                break;
            }
        }
    }

    if (ptr == NULL)
    {
        printf("\nKey not found");
        return root;
    }

    if (ptr->lthread == true && ptr->rthread == true)
    {
        if (par == NULL)
        {
            root = NULL;
        }
        else if (ptr == par->lchild)
        {
            par->lthread = true;
            par->lchild = ptr->lchild;
        }
        else
        {
            par->rthread = true;
            par->rchild = ptr->rchild;
        }
        free(ptr);
    }
    else if (ptr->lthread == false && ptr->rthread == true)
    {
        if (par == NULL)
        {
            root = ptr->lchild;
        }
        else if (ptr == par->lchild)
        {
            par->lchild = ptr->lchild;
        }
        else
        {
            par->rchild = ptr->lchild;
        }
        free(ptr);
    }
    else if (ptr->lthread == true && ptr->rthread == false)
    {
        if (par == NULL)
        {
            root = ptr->rchild;
        }
        else if (ptr == par->lchild)
        {
            par->lchild = ptr->rchild;
        }
        else
        {
            par->rchild = ptr->rchild;
        }
        free(ptr);
    }
    else
    {
        parsucc = ptr;
        succ = ptr->rchild;
        while (succ->lthread == false)
        {
            parsucc = succ;
            succ = succ->lchild;
        }
        if (parsucc == ptr)
        {
            parsucc->rchild = succ->rchild;
        }
        else
        {
            parsucc->lchild = succ->rchild;
        }
        ptr->data = succ->data;
        free(succ);
    }
    return root;
}

//inorder
void inorder(struct node *root)
{
    struct node *temp = root;
    while (temp->lthread == false)
    {
        temp = temp->lchild;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = inorderSucc(temp);
    }
}

//preorder
void preorder(struct node *root)
{
    struct node *temp = root;
    while (temp->lthread == false)
    {
        printf("%d ", temp->data);
        temp = temp->lchild;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = inorderSucc(temp);
    }
}

//postorder
void postorder(struct node *root)
{
    struct node *temp = root;
    while (temp->lthread == false)
    {
        temp = temp->lchild;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = inorderPred(temp);
    }
}

//main
int main()
{
    int ch, i, n, key;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the nodes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        root = insert(root, key);
    }
    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Inorder");
        printf("\n4. Preorder");
        printf("\n5. Postorder");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the key to be inserted: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter the key to be deleted: ");
            scanf("%d", &key);
            root = delete(root, key);
            break;
        case 3:
            printf("Inorder: ");
            inorder(root);
            break;
        case 4:
            printf("Preorder: ");
            preorder(root);
            break;
        case 5:
            printf("Postorder: ");
            postorder(root);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}

