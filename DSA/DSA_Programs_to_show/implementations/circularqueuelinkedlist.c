//circular queue using linked list in c

#include<stdio.h>
#include<stdlib.h>

#define max 10

struct node
{
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

int isFull()
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

int isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

void insert(int item)
{
    if (isFull())
    {
        printf("\nQueue Overflow");
        return;
    }
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = NULL;
    if (front == NULL)
        front = temp;
    else
        rear->link = temp;
    rear = temp;
    rear->link = front;
}

int delete()
{
    struct node *temp;
    int item;
    if (isEmpty())
    {
        printf("\nQueue Underflow");
        return -1;
    }
    temp = front;
    item = temp->data;
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->link;
        rear->link = front;
    }
    free(temp);
    return item;
}

void display()
{
    struct node *p;
    p = front;
    while (p->link != front)
    {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("%d ", p->data);
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be inserted: ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2 :
            item = delete();
            if (item != -1)
                printf("\nDeleted item is %d", item);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
}
