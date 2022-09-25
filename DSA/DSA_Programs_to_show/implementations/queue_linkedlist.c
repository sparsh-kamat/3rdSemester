//implement queue using linked list in C.   Do not declare any global variables.

#include<stdio.h>
#include<stdlib.h>

#define max 10

struct node
{
    int data;
    struct node *link;
};

int isFull(struct node *front, struct node *rear)
{
    struct node *p;
    int count = 0;
    p = front;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }
    if (count == max)
        return 1;
    else
        return 0;
}

int isEmpty(struct node *front, struct node *rear)
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

void insert(struct node **front, struct node **rear, int item)
{
    if (isFull(*front, *rear))
    {
        printf("\nQueue Overflow");
        return;
    }
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = NULL;
    if (*front == NULL)
        *front = temp;
    else
        (*rear)->link = temp;
    *rear = temp;
}

int delete(struct node **front, struct node **rear)
{
    struct node *temp;
    int item;
    if (isEmpty(*front, *rear))
    {
        printf("\nQueue Underflow");
        return -1;
    }
    temp = *front;
    item = temp->data;
    *front = (*front)->link;
    free(temp);
    return item;
}

void display(struct node *front, struct node *rear)
{
    struct node *p;
    if (isEmpty(front, rear))
    {
        printf("\nQueue is empty");
        return;
    }
    p = front;
    printf("\nQueue is : ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
}

int main()
{
    struct node *front = NULL, *rear = NULL;
    int choice, item;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be inserted : ");
            scanf("%d", &item);
            insert(&front, &rear, item);
            break;
        case 2:
            item = delete(&front, &rear);
            if (item != -1)
                printf("\nDeleted item is %d", item);
            break;
        case 3:
            display(front, rear);
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong choice");
        }
    }
    return 0;
}
