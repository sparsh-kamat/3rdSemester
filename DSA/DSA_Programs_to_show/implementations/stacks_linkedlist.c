//implementation of stacks using linked list. Do not declare any global variables.

#include<stdio.h>
#include<stdlib.h>

#define max 10

struct node
{
    int data;
    struct node *link;
};

int isFull(struct node *top)
{
    struct node *p;
    int count = 0;
    p = top;
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

int isEmpty(struct node *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

void push(struct node **top, int item)
{
    if (isFull(*top))
    {
        printf("\nStack Overflow");
        return;
    }
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = *top;
    *top = temp;
}

int pop(struct node **top)
{
    struct node *temp;
    int item;
    if (isEmpty(*top))
    {
        printf("\nStack Underflow");
        return -1;
    }
    temp = *top;
    item = temp->data;
    *top = temp->link;
    free(temp);
    return item;
}

int main()
{
    struct node *top = NULL;
    int choice, item;
    while (1)
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be pushed: ");
            scanf("%d", &item);
            push(&top, item);
            break;
        case 2:
            item = pop(&top);
            if (item != -1)
                printf("\nThe popped item is %d", item);
            break;
        case 3:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}

