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

struct node *create(int post[], int in[], int n)
{
    struct node *p;
    int i, j, k;
    int *lpost, *rpost, *lin, *rin;
    if (n == 0)
        return NULL;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = post[n - 1];
    for (i = 0; i < n; i++)
        if (in[i] == post[n - 1])
            break;
    lpost = (int *)malloc(i * sizeof(int));
    lin = (int *)malloc(i * sizeof(int));
    rpost = (int *)malloc((n - i - 1) * sizeof(int));
    rin = (int *)malloc((n - i - 1) * sizeof(int));
    for (j = 0; j < i; j++)
    {
        lpost[j] = post[j];
        lin[j] = in[j];
    }
    for (k = 0; k < n - i - 1; k++)
    {
        rpost[k] = post[i + k];
        rin[k] = in[i + k + 1];
    }
    p->lchild = create(lpost, lin, i);
    p->rchild = create(rpost, rin, n - i - 1);
    return p;
}

void levelorder(struct node *p, int level)
{
    if (p != NULL)
    {
        if (level == 1)
            printf("%d ", p->data);
        else if (level > 1)
        {
            levelorder(p->lchild, level - 1);
            levelorder(p->rchild, level - 1);
        }
    }
}

void spiralorder(struct node *p, int level, int flag)
{
    if (p != NULL)
    {
        if (level == 1)
            printf("%d ", p->data);
        else if (level > 1)
        {
            if (flag == 1)
            {
                spiralorder(p->lchild, level - 1, flag);
                spiralorder(p->rchild, level - 1, flag);
            }
            else
            {
                spiralorder(p->rchild, level - 1, flag);
                spiralorder(p->lchild, level - 1, flag);
            }
        }
    }
}

int depth(struct node *p)
{
    int x = 0, y = 0;
    if (p != NULL)
    {
        x = depth(p->lchild);
        y = depth(p->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int post[n], in[n];
    printf("\nEnter postorder: ");
    for(int i=0; i<n; i++){
        scanf("%d", &post[i]);
    }
    printf("\nEnter inorder: ");
    for(int i=0; i<n; i++){
        scanf("%d", &in[i]);
    }

    while(1){
        int choice;
        printf("\n1. Create Tree");
        printf("\n2. Display Depth");
        printf("\n3. Display Level Order");
        printf("\n4. Display Spiral Order");
        printf("\n5. quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                root = create(post, in, n);
                printf("\nTree created");
                break;
            case 2:
                printf("\nDepth of tree: %d", depth(root));
                break;
            case 3:
                printf("\nLevel Order: ");
                for(int i=1; i<=depth(root); i++){
                    levelorder(root, i);
                }
                break;
            case 4:
                printf("\nSpiral Order: ");
                for(int i=1; i<=depth(root); i++){
                    spiralorder(root, i, i%2);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
}